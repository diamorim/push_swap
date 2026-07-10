This project has been created as part of the 42 curriculum by <damorim- >, <norobins>.

## Description
In this project, our program recieves instructions from a user 

Program accepts a series of numbers and stores these into a stack 
structure, stack 'a'.

The goal of our program is to sort these numbers in ascending order
using an additional stack, stack 'b', and a limited # of operations.

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

Our program uses 'pa', 'pb', 'ra', 'rb', 'rra' and 'rrb' to sort the elements 
inside and between the stacks.


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
	- 2 or more flags
	- 1 or less arguments


### Flags
Flags are used to force one specific [sorting algorithm](#__Algorithm_requirements__)

The flags available are:
- `--simple`
- `--medium`
- `--complex`
- `--adaptive`

You should add the flags as arguments to the program, the order does not matter so you can choose where to put it.
e.g:
	`- ./push_swap 1 --simple 3 2`

If no flags are used the program will run with `adaptive` setting by default.




### Disorder metric
In terms of recieved input, our program considers any time a 
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


## Algorithm requirements
The program implements four distinct sorting strategies -- in order to sort the
elements and deliver a completely sorted stack 'a'.

- 1. Simple algorithm (O(n²))
- 2. Medium algorithm (O(n√n))
- 3. Complex algorithm  (O(n log n))
- 4. Adaptive algorithm
			 < 0.2  -- simple algorithm
   0.2 <= x <= 0.5  -- medium algorithm
			>= 0.5  -- complex algorithm


## For very small # of inputs: we use `handle_small_sort*()`
For all algorithims we call `handle_small_sort()` to handle cases where there are <= 3
elements to sort.

If there are only 2 inputted elements (& they are not sorted in ascending order), the program:
	-- swaps those two elements

If there are only 3 inputted elements (& they are not sorted in ascending order), the program:
	-- rotates the largest element to the bottom
	-- swaps the top two elements (if appropriate)

We use `handle_small_sort()` for these small amount of inputs because --> for up <=3 elements, there are 
<= 6 permutations and this can most effectively solved by <= 2 operations.


### Simple algorithm (O(n²))
We use a selection sort style algorithm to meet the O(n²) requirement for operations.

A classic selection sort repeatedly finds the smallest element and places it in its final position in sorted order. 

If there are more than 3 elements, our implementation repeatedly (until there are only 3 elements left in stack 'a'):
	- scans stack 'a' for the smallest element;
	- rotates stack 'a' so that the smallest element is located at the 
	top of the stack
	- pushes that element over to stack 'b'

Next, our algorithm sorts these remaining three elements in stack 'a' with `sort_3()`.

After this process, our program pushes each element in stack 'b' -- one-by-one -- back to stack 'a' until stack 'b' is completely empty.


#### O(n²) & simple algorithm
	- Across ~n extractions this algorithm delivers O(n²) operations in the worst case scenario.

	- Each extraction from a stack of size k -- costs at most ⌊k/2⌋ rotations (smart_rotate picks the shorter direction) plus one push. 

	- Summed over n − 3 extractions, the rotations are bounded by (n + (n-1) + ... + 4)/2 ≈ n²/4, so the total operation count is O(n²).

	- O(n√n) and O(n log n) strategies will outperform O(n²) as input grows.



### Medium algorithm (O(n√n)) 
We use a chunk-based sorting strategy that divides the input into chunks of approximately √n consecutive ranks.

1. If there are ≤3 elements, sort them with `handle_small_sort()` and return.

#### 2. Rank every element:####
	Copy all values into an array, `quick_sort()` it, and assign each node its index in the sorted array as its rank.

#### 3. Compute chunks#### 
	- chunk_size        = ⌊√n⌋ (the largest c with c² ≤ n), with a minimum of 2
	- Number of chunks  = ceil(n / chunk_size)

#### 4. Distribute to stack 'b', chunk-by-chunk
	Process chunks in ascending rank order.

	For each chunk [min, max):
		- Scan stack 'a' from the top (forward rotation only - `op_ra`)
		-  When an element whose rank, is within [min, max), reaches the top, push it to stack 'b'
		- Repeat until the whole chunk has been moved
			- A safety guard stops the pass if a full revolution completes without a match
			(defensive, should not trigger in normal use)

5. At the end of phase 1, stack 'b' holds all elements -- with larger ranks generally closer to the top. They are grouped by chunk but not yet completely sorted.

#### 6. Push back to stack 'a'
	- Repeatedly find the element with maximum rank in stack 'b' (find_pos_max)
	- `smart_rotate` it to the top along the shortest direction 
	- Push the element to stack 'a' (`op_pa`)
	- Repeat until stack 'b' is completely empty

The end result is stack 'a' sorted in ascending order. 



#### (O(n√n)) & medium algorithm

- ##### Phase 1: chunking and pushing to stack 'b' 
	- During each chunk pass, the loop rotates forward through a (`op_ra`) and never completes a full revolution without a match — the safety guard stops it first — so each surviving element is rotated past at most once per pass.
	- One `op_pb` per element moved.
	- Across ~√n passes the stack shrinks each time, so total rotations are bounded by n + (n − √n) + (n − 2√n) + … ≈ O(n√n).

- ##### Phase 2: pushing back to stack 'a'
	- n pushes (`op_pa`), each preceded by a smart_rotate to bring stack 'b's max to the top. 
	- Because chunks are pushed in ascending rank order, the current max is always within the top ~√n region of b, so each rotation costs ≤ √n/2 operations → O(n√n) operations.

- ##### Total (worst-case): 
	- O(n√n) operations


For details on our quick sort implementation, see `Quick sort algorithm` section.



### Complex algorithm (O(n log n))
We use an adaptation of LSD (least-significant digit) radix sort to achieve worst-case O(n log n).

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



#### O(n log n) & complex algorithm

- *Bit passes:* `count_bits(n − 1)` ≈ log₂(n) passes (7 for n=100, 9 for n=500).
 - *Per pass:* walks all n elements once — each element costs one operation (op_ra or op_pb) — then pushes them back with ~n op_pa. So each pass ≈ 2n
   operations.
 - *Total:* 2n × log₂(n) = O(n log n) operations.



### `quick_sort` algorithm for computing rank per element
Both `medium_sort()` and `complex_sort()` algorithms utilize `quick_sort` to compute the rank of
values relative to each other within an array. We do not directlyy use `quick_sort()` to perform
sorting operations within- or in-between stacks.

Quick sort works by selecting one element as a pivot and partitioning the rest of the array into two groups — elements smaller than the pivot and elements larger than the pivot — then recursively sorting each group.

Our implementation works as follows:

1. Choose a pivot.
	- We always pick the last element of the current range (`arr[high]`) as the pivot -- this is the archtypeal Lomuto partition scheme.

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



### Performance Benchmarks

For 100 random numbers, our program must use:
	- Less than 2,000 operations to pass (minimum requirement)
	- Less than 1,500 operations for good performance
	- Less than 700 operations for excellent performance


For 500 random numbers, our program must use:
	- Less than 12,000 operations to pass (minimum requirement)
	- Less than 8,000 operations for good performance
	- Less than 5,500 operations for excellent performance


## Resources
- Youtube
- GeekForGeeks
- ChatGPT
- Claude LLM
- Gemini
