#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct Task {
	int low, high;
};
struct Task* quickssort(long* arr,long l, long n)
{
	if(l<n-1)
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
		struct Task* list = malloc(2*sizeof(struct Task));
		list[0].low = (int)l;
		list[0].high = (int)i-1;
		list[1].low= (int)i;
		list[1].high = (int)n;
		return list;
	}
	return NULL;
}
int main()
{
	int n;
	scanf("%d", &n);
	long arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%ld", &arr[i]);
	}
	struct Task stack[n];
	stack[0].low=0;
	stack[0].high=n;
	long top = 0;
	while(top>=0)
	{
		struct Task*appst = quickssort(arr, stack[top].low, stack[top].high);
		if (appst == NULL) top--;
		else
		{
			stack[top].low=appst[1].low;
			stack[top].high=appst[1].high;
			top++;
			stack[top].low=appst[0].low;
			stack[top].high=appst[0].high;
		}
	}
	for(long i = 0; i < n; i++)
	{
		printf("%ld \n", arr[i]);
	}
	return 0;
}
