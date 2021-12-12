#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *dsort(const char* str, long n)
{
	int keys[26] = {0};
	for (long j = 0; j<n;j++)
	{
		int k = (int) str[j];
		keys[k-97]++;
	}
	for(int i = 1;i<26;i++)
	{
		keys[i] += keys[i-1];
	}
	char *res = malloc(n+1);
	for(long j = n -1; j>=0;j--)
	{
		int k = (int) str[j];
		int i = keys[k-97]-1;
		keys[k-97] = i;
		res[i] = str[j];
	}
	res[n] = 0;
	return res;
}
int main()
{
	char str[1000000];
	gets(str);
	puts(dsort(str,(long) strlen(str)));
	return 0;
}
