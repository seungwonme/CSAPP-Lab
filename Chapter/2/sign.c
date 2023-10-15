#include <stdio.h>

typedef unsigned char	*byte_ptr;

void show_bytes(byte_ptr start, int len)
{
	for (int i = 0; i < len; i++)
		printf("%.2x ", start[i]);
	printf("\n");
}

// 2.23
int	fun1(unsigned word) {
	printf("fun1\n");
	unsigned tmp = word << 24;
	show_bytes((byte_ptr) &tmp, sizeof(unsigned));
	tmp >>= 24;
	show_bytes((byte_ptr) &tmp, sizeof(unsigned));
	show_bytes((byte_ptr) (int *)&tmp, sizeof(unsigned));
	return (int)((word << 24) >> 24);
}

int	fun2(unsigned word) {
	printf("fun2\n");
	int tmp = word << 24;
	show_bytes((byte_ptr) &tmp, sizeof(unsigned));
	tmp >>= 24;
	show_bytes((byte_ptr) &tmp, sizeof(unsigned));
	return (int)((word << 24) >> 24);
}

float	sum_elements(float a[], unsigned length)
{
	float result = 0;

	for (int i = 0; i < length - 1; i++)
		result += a[i];
	return (result);
}

int	main(void)
{
	/* int				 i = 0xFFFFFFFF;
	unsigned		ui = i;
	short 			sx = -12345;
	unsigned short usx = sx;
	int				 x = sx;
	unsigned		ux = usx;

	printf("i : %d, ui : %u\n", i, ui);
	show_bytes((byte_ptr) &i, sizeof(int));
	show_bytes((byte_ptr) &ui, sizeof(unsigned));
	show_bytes((byte_ptr) &sx, sizeof(short));
	show_bytes((byte_ptr) &usx, sizeof(unsigned short));
	show_bytes((byte_ptr) &x, sizeof(int));
	show_bytes((byte_ptr) &ux, sizeof(unsigned));

	// 비교 오퍼랜드 중 하나라도 비부호형이면 묵시적으로 비부호형으로 cast된다.
	if (-1 > 0U) printf("-1 > 0U\n");
	if (2147483647 < -2147483647 - 1U) printf("2147483647 < -2147483647 - 1U\n");
	if (2147483647 > (int)2147483648U) printf("2147483647 > (int)2147483648U\n"); */

	/* short		sx = -12345;
	unsigned	uy = sx; // short -> unsigned 크기를 바꾸고 자료형을 바꾼다.

	printf("uy : %u\t", uy);
	show_bytes((byte_ptr) &uy, sizeof(unsigned));
	printf("sx : %i\t", sx);
	show_bytes((byte_ptr) &sx, sizeof(unsigned)); */

	/* unsigned	w[4] = {0x00000076, 0x87654321, 0x000000C9, 0xEDCBA987};
	for (size_t i = 0; i < 4; i++)
		printf("%d, %d\n", fun1(w[i]), fun2(w[i])); */

	/* int		x = 53191;
	short	sx = (short) x; // 32bit int -> 16bit short
	int		y = sx;

	show_bytes((byte_ptr) &x, sizeof(int));
	show_bytes((byte_ptr) &sx, sizeof(int));
	show_bytes((byte_ptr) &y, sizeof(int));
	printf("x : %d, y : %d\n", x, y); */

	float arr[3] = {1, 2, 3};
	sum_elements(arr, 0);
	return (0);
}
