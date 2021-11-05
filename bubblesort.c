#include <stdio.h>

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
void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j))
{
	unsigned long a=0;
	unsigned long b=nel-1;
	int f;
	while (a<b)
	{
		f=1;
		for (unsigned long i=a; i<b; i++)
		{
			if (compare(i, i+1)==1)
			{
				swap(i,i+1);
				f = 0;
			}
		}
		b--;
		for (unsigned long i=b; i>a;i--)
		{
			if (compare(i, i - 1) == -1)
			{
				swap(i, i - 1);
				f = 0;
			}
		}
		a++;
		if (f) break;
	}
}
int main()
{
	bubblesort(8,compare,swap);
	for (unsigned long i=0;i<8;i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
