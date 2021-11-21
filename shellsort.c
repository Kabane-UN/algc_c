#include <stdio.h>
#include <malloc.h>

int arr[] = {3,5,2,7,1,-1,10000,-100};
int compare(unsigned long i, unsigned long j)
{
	if (arr[i]>arr[j])
	{
		return 1;
	} else if (arr[i]<arr[j])
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void swap(unsigned long i, unsigned long j)
{
	int c = arr[i];
	arr[i]=arr[j];
	arr[j]=c;
}
void shellsort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j))
{
	unsigned long lg = 10;
	unsigned long reallg = 0;
	unsigned long * a = malloc(lg * sizeof(unsigned long *));
	unsigned long p1 = 1;
	unsigned long p2 = 1;
	while (p2 < nel)
	{
		a[reallg] = p2;
		unsigned long c = p2;
		p2 = p1 + p2;
		p1 = c;
		reallg++;
		if(reallg == lg)
		{
			lg += lg/2;
			unsigned long * ca =  malloc(lg * sizeof(unsigned long *));
			for (int i = 0; i < reallg; i++)
			{
				ca[i] = a[i];
			}
			free(a);
			a = ca;
		}
	}
	unsigned long d = a[--reallg];
	while (reallg >= 0)
	{
		for (unsigned long i = 1; i < nel; i++)
		{
			unsigned long l = i - 1;
			while ((compare(l, l+1) == 1))
			{
				swap(l+1, l);
				if (l < d ) goto miniend;
				l -= d;
			}
			miniend:;
		}
		if (reallg == 0) goto end;
		d = a[--reallg];
	}
	end:;
}
int main()
{
	shellsort(8, compare, swap);
	for (unsigned long i = 0; i< 8; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
