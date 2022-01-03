#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	long n;
	scanf("%ld\n", &n);
	long *queue = malloc(n*sizeof(long));
	long l = 4;
	long start = 0;
	long end1 = 0;
	long end2 = n-1;
	long qc = 0;
	for (long i = 0; i < n; i++)
	{
		char s[25];
		gets(s);
		if (s[0] == 'D' && s[1] == 'E' && s[2] == 'Q')
		{
			if (end2 == n-1)
			{
				while (end1 != 0)
				{
					end1--;
					long res = queue[end1];
					queue[end2] = res;
					end2--;
				}
			}
			end2++;
			long res = queue[end2];
			printf("%ld\n", res);
		}
		else if  (s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
		{
			long h = strtol(s + 3, NULL, 10);
			queue[end1] = h;
			end1++;
		}
		else if (s[0] == 'M' && s[1] == 'A' && s[2] == 'X')
		{
			long mm = -2000000000;
			for (long j = 0; j<end1; j++)
			{
				if (queue[j] > mm) mm = queue[j];
			}
			for (long j = n-1; j> end2; j--)
			{
				if (queue[j] > mm) mm = queue[j];
			}
			printf("%ld\n", mm);
		}
		else
		{
			if (end1 == 0 && end2== n-1)
			{
				printf("true\n");
			}
			else
			{
				printf("false\n");
			}
		}
	}
	free(queue);
	return 0;
}
