
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
static int	compute_chunk_size(int n)
{
	int	guess;
	int	c;

	guess = 1;
	while (guess * guess <= n)
		guess++;
	c = (guess - 1);
	if (c < MIN_CHUNK_SIZE)
		c = MIN_CHUNK_SIZE;
	if (c > n)
		c = n;
	return (c);
}
