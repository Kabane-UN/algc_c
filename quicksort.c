#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
void ssort(long* arr,long l,long n)
{
	long j = n -1;
	while (j > l)
	{
		long k = j;
		long i = j -1;
		while (i>=l)
		{
			if (arr[k]<arr[i])
			{
				k = i;
			}
			i = i -1;
		}
		long c = arr[k];
		arr[k]=arr[j];
		arr[j]=c;
		j = j- 1;
	}
}
void quickssort(long* arr,long l, long n, long m, long lg)
{
	if(l<n-1)
	{
		if (n < m || lg < 0)
		{
			ssort(arr, l, n);
		}
		else
		{
			long i = l + 1;
			long j = l + 1;
			while (j < n)
			{
				if (arr[j] < arr[l])
				{
					long c = arr[i];
					arr[i] = arr[j];
					arr[j] = c;
					i = i + 1;
				}
				j++;
			}
			long c = arr[i-1];
			arr[i-1] = arr[l];
			arr[l] = c;
			quickssort(arr, l, i-1, m, lg-1);
			quickssort(arr, i , n, m, lg-1);
		}
	}
}
int main()
{
	long n, m;
	scanf("%ld", &n);
	scanf("%ld", &m);
	long arr[n];
	for (size_t i = 0; i < n; i++)
	{
		scanf("%ld", &arr[i]);
	}
	quickssort(arr,0, n, m, (long) ceil(log2((double )n)));
	for (size_t i = 0; i < n; i++)
	{
		printf("%ld\n", arr[i]);
	}
	return 0;
}
