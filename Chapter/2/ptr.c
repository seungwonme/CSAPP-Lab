#include <stdio.h>
#include <string.h>

typedef unsigned char	*byte_ptr;

void	show_bytes(byte_ptr start, int len)
{
	for (int i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void	show_int(int x)
{
	show_bytes((byte_ptr)&x, sizeof(int));
}

void	show_float(float x)
{
	show_bytes((byte_ptr)&x, sizeof(float));
}
void	show_ptr(void *x)
{
	show_bytes((byte_ptr)&x, sizeof(void *));
}
void	test_show_bytes(int val)
{
	int	ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_ptr(pval);
}

// 2.10
void	inplace_swap(int *x, int *y) // *x = 0110 1001, *y = 1001 0110
{
	*y = *x ^ *y; // *y = 1111 1111
	printf("Step 1 : x = %d, y = %d\n", *x, *y);
	*x = *x ^ *y; // *x = 0110 1001
	printf("Step 2 : x = %d, y = %d\n", *x, *y);
	*y = *x ^ *y; // *y = 1001 0110
	printf("Step 3 : x = %d, y = %d\n", *x, *y);
}

// 2.11
void	reverse_arr(int a[], int cnt)
{
	int first, last;
	for (first = 0, last = cnt-1; first < last; first++, last--)
		inplace_swap(&a[first], &a[last]);
}

int	main(void)
{
	// test_show_bytes(12345);
	/* 2.5
	int val = 0x87654321;
	byte_ptr valp = (byte_ptr) &val;
	show_bytes(valp, 1);
	show_bytes(valp, 2);
	show_bytes(valp, 3); */
	/* 2.6
	show_int(3510593);
	show_float(3510593.0); */
	/* 2.7
	const char *s = "abcdef";
	show_bytes((byte_ptr) s, strlen(s)); */
	/* 2.10
	int a = 0x69, b = 0x96;
	inplace_swap(&a, &b); */
	/* 2.11
	 */
	int a[] = {1,2,3,4,5};
	reverse_arr(a, 5);
	for (int i = 0; i < 5; i++)
		printf("%d\n", a[i]);
	return (0);
}
// 00 00 30 39
// 00000000000000000011000000111001
//           01000110010000001110010000000000
//                    *************
// 46 40 e4 00
