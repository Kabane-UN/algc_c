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
long * *kmpall(const char *str1, const char *str2, long n, long m, long*k, long lk)
{
	long *arr = prefix(str1, n);
	long rlk = 0;
	long prlk = -1;
	while (rlk>prlk)
	{
		prlk = rlk;
		long j = 0;
		long i = 0;
		if (rlk != 0)
		{
			i = k[rlk-1]+1;
		}
		for (; i < m; i++)
		{
			while (j > 0 && str1[j] != str2[i])
			{
				j = arr[j - 1];
			}
			if (str1[j] == str2[i])
			{
				j++;
			}
			if (j == n)
			{
				if (rlk + 3 == lk)
				{
					long* ck = malloc(sizeof(long) * lk * 3 / 2);
					lk *= 3 / 2;
					for (long h = 0; h < rlk; h++)
					{
						ck[h] = k[h];
					}
					free(k);
					k = ck;
				}
				k[rlk] = i - n + 1;
				rlk++;
				break;
			}
		}
	}
	long **list = malloc(sizeof(long*)*2);
	list[0]=k;
	list[1] = malloc(sizeof(long));
	list[1][0] = rlk;
	return list;
}
int main(int argc , char ** argv)
{
	long n = (long) strlen(argv[1]);
	long m = (long) strlen(argv[2]);
	long *k = malloc(5*sizeof(long));
	long **u = kmpall(argv[1], argv[2], n, m, k, 5);
	for(long i = 0; i < u[1][0]; i++)
	{
		printf("%ld \n", u[0][i]);
	}
	return 0;
}
