#include <stdio.h>
#include <limits.h>

int	uadd_ok(unsigned x, unsigned y)
{
	return ((x + y) >= x);
}

int	tadd_ok(int x, int y)
{
	/* long long sum = x + y;
	return (INT_MIN > sum | sum > INT_MAX); */
	int pos_overflow = x >= 0 && y >= 0 && x + y < 0;
	int neg_overflow = x < 0 && y < 0 && x + y >= 0;
	return (!pos_overflow && !neg_overflow);
}

int	main(void)
{
	printf("%d\n", uadd_ok(__UINT32_MAX__, __UINT32_MAX__));
	printf("%d\n", tadd_ok(INT_MIN, INT_MAX));
	int	a = INT_MIN;
	int b = -a;
	printf("%d %d\n", a, b);
	return (0);
}
