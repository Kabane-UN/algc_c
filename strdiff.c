#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

int strdiff(char *a, char *b)
{
	int la=(int)strlen(a),lb=(int)strlen(b);
	if (la>lb)
	{
		return lb*8;
	}
	if (lb>la)
	{
		return la*8;
	}
	for (int i=la-1;i>-1;i--)
	{
		if (a[i]!=b[i])
		{
			int c = ((int)a[i])^((int)b[i]);
			int r = 0;
			while (1)
			{
				switch (c&(int)pow(2,r))
				{
					case 0:
						r++;
						break;
					default:
						return (la-i-1)*8+r;
				}
			}
		}
	}
	return -1;
}
int main()
{
    char * s1;
	char * s2;
	s1 = malloc(sizeof(char)*10);
	s2 = malloc(sizeof(char)*10);
	gets(s1);
	gets(s2);
	printf("%d\n",strdiff(s1,s2));
}
