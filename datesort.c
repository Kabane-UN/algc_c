#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct Date {
	int Day, Month, Year;
};
struct Date *dsort(const struct Date* str, long n, int w)
{
	int keys[10] = {0};
	for (long j = 0; j<n;j++)
	{
		int k = (str[j].Year * 10000 + str[j].Month * 100 + str[j].Day)%(int)pow( 10, w+1)/(int)pow( 10, w);
		keys[k]++;
	}
	for(int i = 1;i<10;i++)
	{
		keys[i] += keys[i-1];
	}
	struct Date *res = malloc((n)*sizeof(struct Date));
	for(long j = n -1; j>=0;j--)
	{
		int k = (str[j].Year * 10000 + str[j].Month * 100 + str[j].Day)%(int)pow( 10, w+1)/(int)pow( 10, w);
		int i = keys[k]-1;
		keys[k] = i;
		res[i] = str[j];
	}
	return res;
}
struct Date *datesort(struct Date* arr, long n)
{
	for(int j = 0; j < 8; j++)
	{
		arr = dsort(arr,n,j);
	}
	return arr;
}
int main()
{
	long n;
	scanf("%ld", &n);
	struct Date arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d",  &arr[i].Year, &arr[i].Month, &arr[i].Day);
	}
	struct Date *darr = datesort(arr,n);
	for(int i = 0; i < n; i++)
	{
		printf("%.4d %.2d %.2d\n", darr[i].Year, darr[i].Month, darr[i].Day);
	}
	return 0;
}
