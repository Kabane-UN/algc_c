#include <stdio.h>
#include <string.h>
#include <malloc.h>

unsigned long int steis(char * s1, char * s2)
{
	unsigned long int l1 = strlen(s1), l2 = strlen(s2);
	unsigned long int m = l1,k=0;
	if (m > l2) m = l2;
	for (unsigned long int i = m-1; i > 0; i--)
	{
		for (unsigned long j = 0;j<i;j++)
		{
			if(s1[j]==s2[l2-i+j]) k++;
			else break;
		}
		if (k == i)
		{
			return k;
		}
		k=0;
	}
	return k;
}
unsigned long int strfu(char ** sa, char * s, int n, int sn,int *hhs)
{
	//printf("------%d-------\n", n);
	if (n==0)
	{
		//printf("%ld\n", strlen(s));
		//puts(s);
		return strlen(s);
	}
	if(n == sn)
	{
		int * hs = malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
		{
			hs[i]=0;
		}
		unsigned long int mi = 4294967295;
		for(int i=0; i<n; i++)
		{
			hs[i] = 1;
			unsigned long int res = strfu(sa,sa[i], n-1,sn, hs);
			hs[i] = 0;
			if (res<mi)
			{
				mi=res;
			}
		}
		return mi;
	}
	unsigned long int mi = 4294967295;
	for(int i=0; i<sn; i++)
	{
		if (hhs[i])
		{
			continue;
		}
		unsigned long int r1 = steis(s,sa[i]), r2 = steis(sa[i], s), l1 = strlen(s), l2 = strlen(sa[i]);
		char * a = malloc((l1+l2-r1+1)*sizeof(char));
		strcpy(a,sa[i]);
		strcat(a,s+sizeof(char)*(r1));
		char * b = malloc((l1+l2-r2+1)*sizeof(char));
		strcpy(b,s);
		strcat(b,sa[i]+sizeof(char)*(r2));
		/*puts(s);
		puts(sa[i]);
		printf("%ld\n", r1);
		puts(a);
		printf("%ld\n", r2);
		puts(b);*/
		hhs[i] = 1;
		unsigned long int res = strfu(sa,a, n-1, sn, hhs);
		//unsigned long int resb = strfu(sa,b, n-1,sn, hhs);
		hhs[i] = 0;
		/*if (res > resb)
		{
			res = resb;
		}*/
		if (res<mi)
		{
			mi=res;
		}
	}
	return mi;
}
int main()
{
	int n;
	scanf("%d\n", &n);
	char ** sarr = malloc(n*sizeof(char *));
	for (int i = 0; i < n;i++)
	{
		sarr[i] = malloc(20*sizeof(char));
		gets(sarr[i]);
	}
	if (n==1)
	{
		printf("%ld\n", strlen(*sarr));
	}
	else
	{
		printf("%ld\n", strfu(sarr,NULL,n,n,NULL));
	}
	return 0;
}
