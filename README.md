This project has been created as part of the 42 curriculum by damorim-, norobins.

## Description
Push_swap is an algorithmic sorting project from the 42 curriculum.

The objective is to sort a stack of unique integers using only a restricted 
set of stack operations --> while minimizing the number of operations performed, 
subject to the project's performance thresholds.

This implementation emphasizes algorithmic complexity, optimization, and adaptive strategy 
selection. Rather than relying on a single sorting algorithm, it incorporates four distinct 
sorting strategies and dynamically selects the most appropriate one based on the measured disorder 
of the input stack.

We are allowed to use two stacks and are able to move elements within a stack or between stacks
with a limited number of operations.


| Operation | Description |
| --- | --- |
| sa | Swap first two elements of A |
| sb | Swap first two elements of B |
| ss | sa and sb simultaneously |
| pa | Push from B to A |
| pb | Push from A to B |
| ra | Rotate A upwards |
| rb | Rotate B upwards |
| rr | ra and rb simultaneously |
| rra | Reverse rotate A |
| rrb | Reverse rotate B |
| rrr | rra and rrb simultaneously |

In order to change the order of an element in either stack, the program
must solely use a combination of these 11 operations.

Our program uses a combination of some of these elements to sort them  
inside a stack and between the stacks.


## Contributors
Both damorim- and norobins collaborated closely on architecture, testing, debugging, performance optimization, code review, algorithm analysis, benchmark reporting, documentation and final validation.

We primarily split work across responsibilities below (but collaborated on these areas as well:) 

### damorim-
- Argument parsing and input validation
- Quick sort and binary search implementation for value ranking
- Complex sort algorithm
- Implementation of all required stack operations


### norobins
- Data structure and stack initialization
- Disorder metric computation
- Simple (selection sort) and medium (chunk sort) algorithm implementation
- Adaptive sorting strategy selection


## Instructions

### How to launch the program

1. open your terminal in the root of the project and use the command `make`
2. launch the program with `./push_swap <arguments>`
e.g `./push_swap 3 2 1`


### Restrictions
There are some arguments that are not valid, such as:
	- any non-number character (apart from flags)
	- numbers bigger than the maximum integer
	- numbers lower than the minimum integer
	- floating-point numbers e.g 1.5
	- 2 or more strategy flags (e.g. `--simple` and `--medium` together)

### Flags
Flags are used to force one specific [sorting algorithm](#__Algorithm_requirements__)

The flags available are:
- `--simple`
- `--medium`
- `--complex`
- `--adaptive`

You should add the flags as arguments to the program, the order does not matter so you can choose where to put it.
e.g:
	`./push_swap 1 --simple 3 2`

If no flags are used the program will run with `adaptive` setting by default.

There is also a separate, optional flag that can be used:
- `--bench`

This enables you to print a benchmark report (disorder %, strategy used, and 
operation counts) after sorting completes. It can be combined with 
any of the strategy flags above.

	`./push_swap 1 --bench --simple 3 2`


## Algorithm requirements
The program implements four distinct sorting strategies -- in order to sort the
elements and deliver a completely sorted stack 'a'.

- 1. Simple algorithm (O(n²))
- 2. Medium algorithm (O(n√n))
- 3. Complex algorithm  (O(n log n))
- 4. Adaptive algorithm
			 < 0.2  -- simple algorithm
   0.2 <= x  < 0.5  -- medium algorithm
			>= 0.5  -- complex algorithm

#### Performance benchmarks
- For 100 random numbers, our goal is to achieve between 700 & 2,000 operations
- For 500 random numbers, our goal is to achieve between 5,500 & 12,000 operations:



#### For very small # of inputs: we use `handle_small_sort*()`
For all algorithims we call `handle_small_sort()` to handle cases where there are <= 5
elements to sort.


### Simple algorithm (O(n²))
We use a selection sort style algorithm to meet the O(n²) requirement for operations.

- Time O(n²)
- Space O(1)

A classic selection sort repeatedly finds the smallest element and places it in its final position in sorted order. 

If there are >5 elements in stack 'a', our implementation repeatedly (until there are only 3 elements left in stack 'a'):
	- scans stack 'a' for the smallest element;
	- rotates (or reverse-rotates) stack 'a' so that the smallest element is located at the top of the stack
	- pushes that element over to stack 'b'

Next, our algorithm sorts these remaining three elements in stack 'a' with `sort_3()`.

After this process, our program pushes each element in stack 'b' -- one-by-one -- back to stack 'a' until stack 'b' is completely empty.


#### Why selection sort?
- The implementation here is straight-forward and fits well w/ small data sets and our stack optimization challenge



### Medium algorithm (O(n√n)) 
We use a chunk-based sorting strategy that divides the input into chunks of approximately √n consecutive ranks. 
- Time O(n√n)
- Space O(n)

Assuming there are >5 elements our `medium_sort()` algorithm works as follows:

#### 1. Rank every element:
	Copy all values into an array, `quick_sort()` it, and assign each node its index in the sorted array as its rank.

#### 2. Compute chunks
	- chunk_size        = ⌊√n⌋ (the largest c with c² ≤ n), with a minimum of 2
	- Number of chunks  = (n + chunk_size - 1) / chunk_size
s
#### 3. Distribute to stack 'b', chunk-by-chunk
	Process chunks in ascending rank order.

	For each chunk [min, max):
		- Scan stack 'a' from the top (forward rotation only - `op_ra`)
		-  When an element whose rank, is within [min, max), reaches the top, push it to stack 'b'
		- Repeat until the whole chunk has been moved
			- A safety guard stops the pass if a full revolution plus one extra rotation 
			completes without a match (defensive, should not trigger in normal use)

Once stack 'b' holds all the elements -- the elements with larger ranks are generally closer to the top. These elements are grouped by chunk ---->  but they are not yet, necessarily, perfectly sorted.

#### 4. Push back to stack 'a'
	- Repeatedly find the element with maximum rank in stack 'b' via `find_pos_max()`
	- `smart_rotate` it to the top along the shortest direction 
	- Push the element to stack 'a' (`op_pa`)
	- Repeat until stack 'b' is completely empty

The end result is stack 'a' sorted in ascending order. 


#### Why chunk sort?
- Outperforms O(n²) algorithms and works well w/ medium-sized data sets
- Consistently achieves standards required for operations counts

#### Notes
For details on our quick sort implementation, see `Quick sort algorithm` section.


### Complex algorithm (O(n log n))
- Time O(n log n)
- Space O(n)

We use an adaptation of bitwise radix sort to achieve worst-case O(n log n). 

1. Rank every element (same rank() as `medium sort()` — `quick_sort()` the values, assign each node its sorted index).

 2. Count the bits needed to represent the largest rank (count_bits(stack_size - 1)
	— e.g.  100 elements → ranks 0–99  → 7 bits;
 			500 elements → ranks 0–499 → 9 bits).

 3. For each bit position, starting from the least-significant (bit 0):
	- Walk through every element currently in stack 'a'.
	- If that bit of the rank is 1 → `op_ra` (leave it in stack 'a').
	- If that bit is 0 → `op_pb` (push to stack 'b').
	- After one full pass, push everything from stack 'b' back to stack 'a' (`push_all_to_stack_a`).
	- Early-exit if a is already fully sorted (`is_stack_a_sorted`).

4. Repeat for the next bit position until all bits are processed.

The end result is stack 'a' is sorted in ascending order.



#### Why radix sort?
- Radix sort works particularly well for larger data sets.
- This algorithm consistently achieves our operation count goals and works well with optimizing stacks




### `quick_sort` algorithm for computing rank per element
Both `medium_sort()` and `complex_sort()` algorithms utilize `quick_sort` to compute the rank of
values relative to each other within an array. We do not directly use `quick_sort()` to perform
sorting operations within- or in-between stacks.

Quick sort works by selecting one element as a pivot and partitioning the rest of the array into two groups — elements smaller than the pivot and elements larger than the pivot — then recursively sorting each group.

Our implementation works as follows:

1. Choose a pivot.
	- We always pick the last element of the current range (`arr[high]`) as the pivot -- this is the archetypal Lomuto partition scheme.

2. Partition. Scan through the range with two indices:
 	- `i` tracks the boundary between the "smaller than pivot" group and the rest (starts one before low).
	- `j` scans every element from `low` to `high - 1`.
	- Whenever `arr[j] < pivot`, we increment `i` and swap `arr[i]` with `arr[j]` — growing the "smaller" group by one.

3. Place the pivot. 
	- After the scan, swap the pivot (`arr[high]`) into position i + 1. 
	- The pivot is now in its final sorted position, with everything smaller to its left and everything larger to its right.

4. Recurse.
	- The partition step returns the pivot's index `pivot_idx`
	- Recursively quick-sort the sub-ranges `[low, pivot_idx-1]` and `[pivot_idx +1, high]`.

5. Base case. 
	- When `low >= high`, the range has zero or one element and is already sorted — `return`.

After the sort completes, `binary_search` is used to look up each node's value in the sorted array; its index becomes that node's rank.




### Adaptive algorithm
When there is no flag received as input the adaptive algorithm is the default algorithm.

Program uses an adaptive algorithm dispatcher to utilize a `sort_simple()`, `sort_medium()` or `sort_complex()` algorithm depending on the amount of disorder.

The appropriate algorithm is dispatched based on the computed disorder as defined below via `Disorder metric`:
			 < 0.2  -- simple algorithm
   0.2 <= x < 0.5  -- medium algorithm
			>= 0.5  -- complex algorithm

The adaptive algorithm is very effective because a `sort_simple()` approach can end up more efficient than the other algorithms
if the data is already almost perfectly sorted.

For larger, higher disorder data sets, the `sort_complex()` is going to be our best performer.. 



### Disorder metric
In terms of received input, our program considers any time a 
larger number appears before a smaller number to be a 'mistake' aka 
an instance of disorder.

Per the subject:
- If the numbers are already in the right order, the disorder is 0. 
- If they are in the worst possible order, the disorder is 1. 
- Anything in between means your stack is partly sorted, but still messy.

Our program measures disorder on a scale from 0 to 1 based on the number
of mistakes
	mistakes = 0
	total_pairs = 0
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs

Program measures disorder before any sorting operations are made.

This disorder metric is used by the adaptive algorithm -- which is the 
default algorithm for the program and can also be proactively selected by 
the user to sort the input.



## Resources

#### References
- 42 Peers :-)
- YouTube & related websites
	- BroCode, CS50, GeekForGeeks, Michael Sambol, Oceano, Polylog, Portfolio Courses, etc.
- "Grokking Algorithms" by Aditya Bhargava


#### AI 
LLM tools used for
- General research, project planning & visualization
- Reviewing & visualizing algorithmic concepts
- Assistance with debugging
