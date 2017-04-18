#include <stdio.h>
#include <math.h>
int sum_array_iter(int *arr, int n, int num, int sum)
{
	if (num == n) {
		return sum;
	}
	return sum_array_iter(arr, n, num + 1, arr[num] + sum);
}

int sum_array_recur(int *arr, int n)
{
	if (n == -1) {
		return 0;
	}
	return arr[n] + sum_array_recur(arr, n - 1);
}

int sum_array(int *arr, int n)
{
	return sum_array_iter(arr, n, 0, 0);
}

int fiban_iter(int n, int num, int sum, int lastsum)
{
	if (num >= n)
	{
		return sum;
	}
	printf("%d\n", num);
	return fiban_iter(n, num + 1, sum + lastsum, sum);
}

int fiban_recur(int n)
{
	printf("f(%d)\n", n);
	if (n == 0) {
		return 1;	
	}
	if (n == 1) {
		return 1;	
	}
	int result = fiban_recur(n - 1) + fiban_recur(n - 2);
	return result;
}

int fiban(int n)
{
	return fiban_iter(n, 0, 1, 0);
}

char *int_to_char_iter(int num, char *const arr, const int n, int char_pos, int num_pos)
{
	if (char_pos == n || num_pos == 0) {
		arr[n - 1] = 0;
		return arr;
	}
	arr[char_pos] = '0' + ((abs(num) % (int)pow(10, num_pos)) / pow(10, num_pos - 1));
	char_pos++;
	num_pos--;
	return int_to_char_iter(num, arr, n, char_pos, num_pos);
}

char *int_to_char(int num, char *const arr, const int n)
{
	int size = 1;
	for (int i = num; i / 10 != 0; i /= 10) {
		size++;
	}
	int pos = 0;
	if (num < 0 && n > 2) {
		arr[0] = '-';
		pos++;
		if (n == 2) {
			arr[1] = 0;
			return arr;
		}
	}
	return int_to_char_iter(num, arr, n, pos, size);
}

int main()
{
	//int arr[5] = {0, 1, 2, 3, 4};
	//printf("%d\n", sum_array(arr, 5));
	//printf("%d\n", fiban(10));
	int n = 10;
	char arr[n];
	
	printf("%s\n", int_to_char(35634, arr, n));
	return 0;
}