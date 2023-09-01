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
	printf("Start  : x = %d, y = %d\n", *x, *y);
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
	for (int first = 0, last = cnt - 1;
		first < last;
		first++, last--)
		inplace_swap(&a[first], &a[last]);
}

void	print_arr(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("arr[%zu] : %d\n", i, arr[i]);

}

// 2.13
int	bis(int x, int m)
{
	int result = x | m;
	printf("bis\nx      : ");
	show_bytes((byte_ptr)&x, 4);
	printf("m      : ");
	show_bytes((byte_ptr)&m, 4);
	printf("result : ");
	show_bytes((byte_ptr)&result, 4);
	return (result);
}

int	bic(int x, int m)
{
	int result = x & ~m;
	printf("bic\nx      : ");
	show_bytes((byte_ptr)&x, 4);
	printf("m      : ");
	show_bytes((byte_ptr)&m, 4);
	printf("result : ");
	show_bytes((byte_ptr)&result, 4);
	return (result);
}

int	main(void)
{
	// 2.5
	/* int a = 0x12345678;
	byte_ptr ap = (byte_ptr) &a;
	show_bytes(ap, 1);
	show_bytes(ap, 2);
	show_bytes(ap, 3); */
	// 2.6
	/* show_int(2607352);
	show_float(2607352.0); */
	// 2.7 show_bytes((byte_ptr) "12345", 6);
	/* const char *m = "mnopar";
	show_bytes((byte_ptr) m, strlen(m)); */
	// 2.10
	/* int x = 0x69, y = 0x96;
	inplace_swap(&x, &y); */
	// 2.11
	/* int	arr[] = {1, 2, 3, 4, 5};
	reverse_arr(arr, 5);
	print_arr(arr, 5); */
	// 2.12
	/* unsigned int a = 0x87654321 ^ 0xFFFFFF00;
	unsigned int *p = &a;
	show_bytes((byte_ptr)p, 4); */
	// 2.13
	/* bis(0x00,0xFFFFFFFF);
	bic(0xFFFFFFFF, 0xFFFFFF); */
	/* int a = 0, *p = NULL;
	if (a && 5 / a) printf("division by zero\n");
	if (p && *p++) printf("null pointer ref"); */
	return (0);
}

/* 00 27 c8 f8
00000000001001111100100011111000
           *********************
  01001010000111110010001111100000
4a 1f 23 e0*/
