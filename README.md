# push_swap





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

## Files

### Stacks

- [stack_utils_00_init.c](stacks_prog/stack_utils_00_init.c)