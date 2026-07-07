#include "../push_swap.h"

#define MIN_CHUNK_SIZE 2

/*
	n is the number of elements in the stack.

	Function returns approximately the square root
	of the number of elements in the stack.

	(e.g. if	n = 100 c = 10,
				n = 17	c = 4
				n = 16	c = 4
				n = 15	c = 3
				n = 15	c = 3)
*/
int	compute_chunk_size(int n)
{
	int	guess;
	int	c;
	//n = 9
	guess = 1;
	while (guess * guess <= n)
		guess++;
	// guess = 0
	c = (guess - 1);
	//c = 2
	if (c < MIN_CHUNK_SIZE)
		c = MIN_CHUNK_SIZE;
	if (c > n)
		c = n;
	return (c);
}
