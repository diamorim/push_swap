This project has been created as part of the 42 curriculum by <dammori-m>, <norobins>.

#Description#
In this project, our program recieves instructions from a user 

Program accepts a series of numbers and stores these into a stack 
structure, 'stack a'.

The goal of our program is to sort these numbers in ascending order
using an additional  stack structure, 'stack b' and a limited set of 
operations.

Here is the formatted Markdown table for your operations and descriptions.

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


__ Disorder metric __
In terms of recieved input, our program considers any time a 
larger number appears before a smaller number to be a 'mistake' aka 
an instance of disorder.

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


__ Algorithm requirements __
The program implements four distinct sorting strategies -- in order to sort the
elements and deliver a completely sorted stack 'a'.

- 1. Simple algorithm (O(n²))
- 2. Medium algorithm (O(n√n))
- 3. Complex algorithm  (O(n log n))
- 4. Adaptive algorithm
	-  < 0.2        -- simple algorithm
	-    0.2 <= 0.5 -- medium algorithm
	- >= 0.5        -- complex algorithm


_____ Very small # of inputs _____
For all algorithims:

If there are only 2 inputted elements (& they are not sorted in ascending order), the program:
	-- swaps those two elements

If there are only 3 inputted elements (& they are not sorted in ascending order), the program:
	-- rotates the largest element to the bottom
	-- swaps the top two elements (if appropriate)


_____ Simple algorithm (O(n²)) ____
We chose a selection sort style algorithm to meet the O(n²) requirement.

A classic selection sort repeatedly finds the smallest element and places it in its final position. Our version instead extracts each smallest element to stack 'b' and relies on the LIFO nature of the stacks to place them correctly when they are pushed back to 'a'.

The algorithm proceeds as follows:

- While stack 'a' has more than 3 elements, repeatedly scans 'a' to find the minimum value, rotates the smallest element to the top of the stack 'a', and pushes it to stack 'b'.
- When 3 elements remain in stack 'a', sorts them with sort_3(). 
- Push every element from 'b' to 'a', one-by-one.

Because each of the ~n extraction passes scans up to n elements, the comparison count is O(n²). 

As input size grows, this is outperformed by O(n√n) and O(n log n) strategies.



_____ Medium algorithm (O(n√n)) _____
We use a chunk-based sorting strategy that divides the input into chunks of approximately √n consecutive ranks.

1. If there are ≤3 elements, sort them with handle_small_sort() and return

2. Rank every element: copy all values into an array, quick-sort it, and assign each node its index in the sorted array as its rank.

3. Compute a chunk size of ⌊√n⌋ (the largest c with c² ≤ n), with a minimum of 2
	Compute the number of chunks as ceil(n / chunk_size)

4. Distribute to stack 'b', chunk-by-chunk. Process the chunks in ascending rank order.

	For each band [min, max):
		-- Rotate stack 'a' until an element whose rank falls within the targeted chunk reaches the top
 		-- Push the element to stack 'b'
		-- Repeat until the whole chunk has been processed

5. At the end of phase 1, stack 'b' holds all elements with larger ranks generally nearer the top (loosely grouped, not yet strictly sorted).

6. Rotate to identify the largest elements, and push back to stack 'a' 
	-- Repeatedly find the maximum rank in stack 'b'
	-- Smart_rotate it to the top (shortest direction)
	-- Push it to stack 'a'
	-- Repeat until stack 'b' is completely empty

The end result is stack 'a' sorted in ascending order. Correctness comes from phase 2's per-element max-scan; phase 1's chunk-only reduces how far the max can be from the top of b.

For details on our quick sort implementation, see "_____ Quick sort algorithm _____".



What makes medium_sort() perform at  O(n√n):
- ~√n chunks -- each potentially scanning the whole remaining stack once -----> O(n) per chunk x √n chunks = O(n√n for phase 1.
- Moving elements from stack 'b' to stack 'a' performs a max-scan per element over a shrinkingstack ----> also roughly O(n√n).






_____ Complex algorithm (O(n log n)) _____
We implemented an adaptation of LSD (least-significant digit) radix sort to sort using O(n log n).




_____ Quick sort algorithm _____
Quick sort is a 'divide-and-conquer' sorting algorithm that we use with both medium sort and complex sort. 

Quick sort works by selecting one element as a pivot and partitioning the rest of the array into two groups — elements smaller than the pivot and elements larger than the pivot — then
recursively sorting each group.

Our implementation uses the Lomuto partition scheme, which works as follows:

1. Choose a pivot.
	-- We always pick the last element of the current range (arr[high]) as the pivot.

2. Partition. Scan through the range with two indices:
 	-- i tracks the boundary between the "smaller than pivot" group and the rest (starts one before low).
	-- j scans every element from low to high - 1.
	-- Whenever arr[j] < pivot, we increment i and swap arr[i] with arr[j] — growing the "smaller" group by one.

3. Place the pivot. 
	-- After the scan, swap the pivot (arr[high]) into position i + 1. 
	-- The pivot is now in its final sorted position, with everything smaller to its left and everything larger to its right.

4. Recurse.
	-- The partition step returns the pivot's index pivot_idx
	-- Recursively quick-sort the sub-ranges [low, pivot_idx-1] and [pivot_idx +1, high].

5. Base case. 
	-- When low >= high, the range has zero or one element and is already sorted — return.

After the sort completes, binary_search is used to look up each node's value in the sorted array; its index becomes that node's rank.

Complexity: average and best case O(n log n); worst case O(n²) when the pivot consistently lands at an extreme (e.g. already-sorted input with a last-element pivot — the Lomuto weakness). This is acceptable here because the sort runs once during setup, not per-operation.



_____ Performance Benchmarks _____

For 100 random numbers, our program ust use:
	- Less than 2,000 operations to pass (minimum requirement)
	- Less than 1,500 operations for good performance
	- Less than 700 operations for excellent performance


For 500 random numbers, our program ust use:
	- Less than 12,000 operations to pass (minimum requirement)
	- Less than 8,000 operations for good performance
	- Less than 5,500 operations for excellent performance


Instructions



Resources







___ Big $O$ notation ___

Big $O$ describes the "worst case" or "slowest"
an algorithm will be over time as the number of elements
grows.


----------------------------------------------------------
----------------------------------------------------------
																		Speed in 
																		worst-case
Big O				- type									(as n increases)
----------------------------------------------------------
O(1)				- constant time				- 'Fastest'
O(log n)		- logarithmic time		- 'Fast'
O(n)				- linear time					- 'OK'
O(n log n)	- linearithmic				- 'OK-slow'
O(n 1.5)		- semi-quadratic			- 'Slow'
O(n2)				- quadratic						- 'Slower'
O(2n)				- exponential					- 'Slowest'

Our assignment requires that we use

							algorithm						type
------------------------------------------------
-- simple			O(n2) algorithm			quadratic
-- medium			O((n√n) algorithm		semi-quadratic
-- complex		O (n log n) 				linearithmic
-- adaptive		(one of the above depending on 
							'disorder' metric)


The complexity of a given algorithim can 
typically guestimated by looking at:
- number of loops; and
- how data is split

That is not a definitive statement :-). I'm
not sure I'mn describing perfectly. Just some
notes.


Typical 0 (n2) algorithm patterns are:
- Bubble sort
- Selection sort
- Insertion sort

We are allowed to be more efficient than O(n2)
-- the task for the 'simple' algorithm is to be
worst case O (n2) meaning if n scales towards
infinity, the algorithms worst case is O (n2).
