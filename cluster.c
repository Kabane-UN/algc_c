#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int main()
{
	long n, m;
	scanf("%ld", &n);
	scanf("%ld", &m);
	long pq[n];
	long cpq = 0;
	long restyme = 0;
	for (long i = 0; i < m; i++)
	{
		long t1, t2;
		scanf("%ld %ld", &t1, &t2);
		if (cpq != n)
		{
			long ii = cpq;
			cpq++;
			pq[ii] = t1 + t2;
			while ((ii > 0) && (pq[(ii - 1) / 2] > pq[ii]))
			{
				long c = pq[(ii - 1) / 2];
				pq[(ii - 1) / 2] = pq[ii];
				pq[ii] = c;
				ii = (ii - 1) / 2;
			}
		}
		else
		{
			restyme += pq[0];
			for (long j = 1; j<cpq;j++)
			{
				pq[j] -= pq[0];
			}
			t1-=restyme;
			if (t1<0) t1 = 0;
			pq[0] = t2+t1;
			long ii = 0;
			while (1)
			{
				long l = 2 * ii + 1;
				long r = l + 1;
				long j = ii;
				if ((l < cpq) && pq[ii] > pq[l])
				{
					ii = l;
				}
				if ((r < cpq) && pq[ii] > pq[r])
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
	n = cpq;
	for(long i = 0; i<n;i++)
	{
		restyme += pq[0];
		cpq--;
		if (cpq>0)
		{
			for (long j = 1; j < cpq+1; j++)
			{
				pq[j] = pq[j] - pq[0];
			}
			pq[0] = pq[cpq];
			long ii = 0;
			while (1)
			{
				long l = 2 * ii + 1;
				long r = l + 1;
				long j = ii;
				if ((l < cpq) && pq[ii] > pq[l])
				{
					ii = l;
				}
				if ((r < cpq) && pq[ii] > pq[r])
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
	printf("%ld\n", restyme);
	return 0;
}
