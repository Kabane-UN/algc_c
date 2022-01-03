#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	long n;
	scanf("%ld\n", &n);
	long *queue = malloc(4*sizeof(long));
	memset(queue, 0, 4*sizeof(long));
	long l = 4;
	long start = 0;
	long end = 0;
	long qc = 0;
	for (long i = 0; i < n; i++)
	{
		char s[25];
		gets(s);
		if (s[0] == 'D' && s[1] == 'E' && s[2] == 'Q')
		{
			long res = queue[start];
			start++;
			if (start == l)
			{
				start = 0;
			}
			qc--;
			printf("%ld\n", res);
		}
		else if  (s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
		{
			long h = strtol(s+3, NULL, 10);
			if (qc == l)
			{
				l = l*2;
				long *c = malloc(l*sizeof(long));
				memset(c, 0, l*sizeof(long));
				for (int j = 0; j < l/2; j++)
				{
					if (j<end)
					{
						c[j] = queue[j];
					}
					else
					{
						c[j+n/2-1] = queue[j];
						if (j == start)
						{
							start+=n/2-1;
						}
					}
				}
				free(queue);
				queue = c;
			}
			queue[end] = h;
			end++;
			qc++;
			if (end == l && qc != l)
			{
				end = 0;
			}
		}
		else
		{
			if (qc == 0)
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
	printf("%ld\n", l);
	printf("%ld\n", qc);
	return 0;
}
