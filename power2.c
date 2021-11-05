#include <stdio.h>
#include <malloc.h>
#include <math.h>
unsigned long lgtwo (long * a, int n)
{
	long * b = malloc (sizeof (long) *((long)pow(2, n) -1-n));
	unsigned long k = 0;
	long v = 0;
	if ((log((double)a[0])-(int) log((double)(a[1]))) == 0)
	{
		k++;
	}
	for (int i = 1; i < n; i++)
	{
		long * g = malloc (sizeof (long) * (v+i));

		for (long j = 0; j < v; j++)
		{
			double d = log2((double)(b[j]+a[i]));
			g[j] = (b[j]+a[i]);
			if ((d-(int) d) == 0)
			{
				k++;
			}
		}
		for (long j = 0; j < i; j++)
		{
			double d = log2((double)(a[j]+a[i]));
			g[j+v] = (a[j]+a[i]);
			if ((d-(int) d) == 0)
			{
				k++;
			}
		}
		double d = log2((double)(a[i]));
		if ((d-(int) d) == 0)
		{
			k++;
		}
		for (long j = 0; j < (v+i); j++)
		{
			b[v+j] = g[j];
		}
		v += v+i;
		free(g);
	}
	free(b);
	return k;
}
int main()
{
	int n;
	scanf("%d", &n);
	long * a = malloc(n*sizeof(long));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (n < 2)
	{
		printf("%d\n", 0);
	} else
	{
		printf("%ld\n", lgtwo(a, n));
	}
	return 0;
}
