#include <stdio.h>

int	main(void)
{
	// 1e20 = 1 * 10^20(100000000000000000000.0)
	printf("%.2lf\n", (3.14 +1e20) - 1e20); // 0.00
	printf("%.2lf\n", 3.14 + (1e20 - 1e20)); // 3.14
	return (0);
}
