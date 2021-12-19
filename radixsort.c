#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
union Int32 {
	int x;
	unsigned char bytes[4];
};
union Int32 *dsort(const union Int32* str, long n, int w)
{
	int keys[256] = {0};
	for (long j = 0; j<n;j++)
	{
		int k = str[j].bytes[w];
		keys[k]++;
	}
	for(int i = 1;i<256;i++)
	{
		keys[i] += keys[i-1];
	}
	union Int32 *res = malloc((n)*sizeof(union Int32));
	for(long j = n -1; j>=0;j--)
	{
		int k = str[j].bytes[w];
		int i = keys[k]-1;
		keys[k] = i;
		res[i] = str[j];
	}
	return res;
}
union Int32 *radixsort(union Int32 *arr, long n)
{
	for(int j = 0; j < 4; j++)
	{
		arr = dsort(arr,n,j);
	}
	return arr;
}
int main()
{
	long n;
	scanf("%ld", &n);
	union Int32 arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d",  &arr[i].x);
	}
	union Int32 *darr = radixsort(arr,n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", darr[i].x);
	}
	return 0;
}
