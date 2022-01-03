#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


int main()
{
	long n;
	scanf("%ld", &n);
	long arn[n];
	long sum = 0;
	for (long i = 0; i<n;i++)
	{
		scanf("%ld", &arn[i]);
		sum += arn[i];
	}
	long pq[sum];
	long cpq = 0;
	for (long i = 0; i<sum;i++)
	{
		long x;
		scanf("%ld", &x);
		long ii = cpq;
		cpq++;
		pq[ii] = x;
		while ((ii > 0) && (pq[(ii-1)/2] > pq[ii]))
		{
			long c = pq[(ii-1)/2];
			pq[(ii-1)/2] = pq[ii];
			pq[ii] = c;
			ii = (ii-1)/2;
		}
	}
	for (long i = 0; i<sum;i++)
	{
		printf("%ld\n", pq[0]);
		cpq --;
		if (cpq > 0)
		{
			pq[0] = pq[cpq];
			long ii = 0;
			while (1)
			{
				long l = 2*ii+1;
				long r = l+1;
				long j = ii;
				if ((l<cpq) && pq[ii] > pq[l])
				{
					ii = l;
				}
				if ((r<cpq) && pq[ii] > pq[r])
				{
					ii = r;
				}
				if (ii == j)
				{
					break;
				}
				long c = pq[ii];
				pq[ii] = pq[j];
				pq[j] = c;
			}
		}
	}
	return 0;
}
