#include <stdio.h>
#include <malloc.h>
#include <string.h>

void csort(char *src, char *dest)
{
	char ** buf = malloc(strlen(src)*sizeof(char *));
	buf[0] = malloc(strlen(src)+1);
	unsigned long j = 0;
	unsigned long k = 0;
	for (size_t i = 0; i < strlen(src);i++)
	{
		if(src[i] == ' ')
		{
			if (k!=0)
			{
				buf[j + 1] = malloc(strlen(src) + 1);
				buf[j][k] = 0;
				j++;
				k = 0;
			}
		}
		else
		{

			buf[j][k++] = src[i];
		}
	}
	if(k != 0) buf[j][k] = 0;
	j++;
	unsigned long * key = malloc(j*sizeof(unsigned long));
	for (int i = 0; i<j; i++)
	{
		key[i] = strlen(buf[i]);
	}
	unsigned long count[j];
	memset(count, 0, j*sizeof(unsigned long));
	for (unsigned long i = 0; i<j-1; i++)
	{
		for (unsigned long v = i+1; v<j; v++)
		{
			if (key[i]>key[v])
			{
				count[i] += 1;
			}
			else
			{
				count[v] += 1;
			}
		}
	}
	free(key);
	k = 1;
	char ** nbuf = malloc(j*sizeof(char *));
	for (unsigned long i = 0; i<j;i++)
	{
		nbuf[count[i]] = malloc(strlen(buf[i])+1);
		strcpy(nbuf[count[i]], buf[i]);
		k += strlen(buf[i]);
		free(buf[i]);
	}
	free(buf);
	strcpy(dest, nbuf[0]);
	free(nbuf[0]);
	for (unsigned long i = 1; i<j;i++)
	{
		strcat(dest, " ");
		strcat(dest, nbuf[i]);
		free(nbuf[i]);
	}
	free(nbuf);
}

int main()
{
	char s[] = "qqq  www  t  aa rrr  bb  x y zz";
	char * buf = malloc(strlen(s)+1);
	csort(s, buf);
	puts(buf);
	return 0;
}
