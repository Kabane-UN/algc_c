#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long *prefix(const char *str, long n)
{
	long *arr = malloc(sizeof(long)*n);
	arr[0] = 0;
	long t = 0;
	for(long i = 1; i < n; i++)
	{
		while (t>0 && str[t]!=str[i])
		{
			t = arr[t-1];
		}
		if (str[t]==str[i])
		{
			t+=1;
		}
		arr[i]= t;
	}
	return arr;
}
long rec(long *arr, long v)
{
	if (arr[v]!=0)
	{
		if (arr[v]*2<(v+1))
		{
			return -1;
		}
		else return rec(arr, arr[v]-1);
	}
	else
	{
		return v+1;
	}
}
int main(int argc , char ** argv)
{
	long n = (long) strlen(argv[1]);
	long *arr = prefix(argv[1], n);
	for (long i=0; i<n; i++)
	{
		long j = rec(arr, i);
		if (j == -1 || arr[i] == 0) continue;
		printf("%ld %ld\n",i+1 ,(i+1)/j);
	}
	printf("\n");
	return 0;
}
