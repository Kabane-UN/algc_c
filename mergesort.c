#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void psort(long* a ,unsigned long p,unsigned long n)
{

	for (unsigned long i = p+1; i < n+1; i++)
	{
		unsigned long l = i - 1;
		while (labs(a[l]) > labs(a[(l+1)]))
		{
			long c = a[l+1];
			a[l+1]=a[l];
			a[l]=c;
			if (l < 1+p) goto miniend;
			l -= 1;
		}
	miniend:;
	}
}
void m(long * a,unsigned long p,unsigned long mean, unsigned long n);
void conputsort(long * a,unsigned long p, unsigned long n)
{
	if (p<n)
	{
		if (n-p+1<6)
		{
			psort(a,p,n);
		}
		else
		{
			unsigned long mean = (p + n) / 2;
			conputsort(a, p, mean);
			conputsort(a, mean + 1, n);
			m(a, p, mean, n);
		}
	}
}
void m(long * a,unsigned long p,unsigned long mean, unsigned long n)
{
	long b[n-p+1];
	unsigned long j = p;
	unsigned long k = mean+1;
	for (unsigned long i = 0; i < n-p+1; i++)
	{
		if (k > n)
		{
			b[i]=a[j];
			j++;
		}
		else if (j > mean)
		{
			b[i]=a[k];
			k++;
		}
		else if (labs(a[j])<labs(a[k]))
		{
			b[i]=a[j];
			j++;
		}
		else if (labs(a[j])>labs(a[k]))
		{
			b[i]=a[k];
			k++;
		}
	}
	j=0;
	for (unsigned long i = p; i < n+1; i++)
	{
		a[i] = b[j++];
	}
}
int main()
{
	unsigned long n;
	scanf("%ld", &n);
	long a[n];
	for (unsigned long i = 0; i < n; i++)
	{
		scanf("%ld", &a[i]);
	}
	conputsort(a,0,n-1);
	for (unsigned long i = 0; i < n; i++)
	{
		printf("%ld\n",a[i]);
	}
	return 0;
}
