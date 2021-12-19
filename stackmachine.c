#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	long n;
	scanf("%ld\n", &n);
	long stack[n];
	long top = -1;
	for (long i = 0; i < n; i++)
	{
		char s[25];
		gets(s);
		int l = (int) strlen(s);
		if (l > 4)
		{
			long h = strtol(s+5, NULL, 10);
			stack[++top] = h;
		}
		else if (l == 4)
		{
			long c = stack[top];
			stack[top] = stack[top-1];
			stack[top-1] = c;
		}
		else if (s[0]=='A' && s[1]=='A' && s[2]=='D')
		{
			stack[top-1]+=stack[top];
			top--;
		}
		else if (s[0]=='S' && s[1]=='U' && s[2]=='B')
		{
			stack[top-1]=stack[top]-stack[top-1];
			top--;
		}
		else if (s[0]=='M' && s[1]=='U' && s[2]=='L')
		{
			stack[top-1]*=stack[top];
			top--;
		}
		else if (s[0]=='D' && s[1]=='I' && s[2]=='V')
		{
			stack[top-1]=stack[top]/stack[top-1];
			top--;
		}
		else if (s[0]=='M' && s[1]=='A' && s[2]=='X')
		{
			stack[top-1]=((stack[top-1]) > (stack[top])) ? (stack[top-1]) : (stack[top]);
			top--;
		}
		else if (s[0]=='M' && s[1]=='I' && s[2]=='N')
		{
			stack[top-1]=((stack[top-1]) < (stack[top])) ? (stack[top-1]) : (stack[top]);
			top--;
		}
		else if (s[0]=='N' && s[1]=='E' && s[2]=='G')
		{
			stack[top]*=-1;
		}
		else
		{
			stack[top+1]=stack[top];
			top++;
		}
	}
	printf("%ld", stack[0]);
	return 0;
}
