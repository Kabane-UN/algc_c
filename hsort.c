#include <stdio.h>
#include <malloc.h>
#include <string.h>

int compare (const void *a, const void *b)
{
	if (strlen(a)>strlen(b))
	{
		return 1;
	}
	else if (strlen(a)<strlen(b))
	{
		return -1;
	}
	return 0;
}
void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b))
{
	size_t as = nel/2-1;
	for (size_t i = as; i >= 0; i--)
	{
		size_t a = i;
		while (1)
		{
			size_t w = width;
			size_t n = nel;
			size_t l = a+ 1;
			size_t r = 2*a+ 1;
			size_t b = a;
			if ((l<n) && compare(base+l*w, base+a*w) == 1)
			{
				a = l;
			}
			if ((r<n) && compare(base+r*w, base+a*w) == 1)
			{
				a = r;
			}
			if (b == a)
			{
				break;
			}
			void * c = malloc(sizeof(void)*w);
			memcpy(c, base+a*w, w);
			memcpy(base+a*w, base+b*w, w);
			memcpy(base+b*w, c, w);

		}
		if (i==0) goto end;
	}
end:;
	for (size_t i = nel-1; i > 0;i--)
	{
		void * c = malloc(sizeof(void)*width);
		memcpy(c, base, width);
		memcpy(base, base+i*width, width);
		memcpy(base+i*width, c, width);
		size_t a = 0;
		while (1)
		{
			size_t w = width;
			size_t n = i;
			size_t l = a+ 1;
			size_t r = 2*a+ 1;
			size_t b = a;
			if ((l<n) && compare(base+l*w, base+a*w) == 1)
			{
				a = l;
			}
			if ((r<n) && compare(base+r*w, base+a*w) == 1)
			{
				a = r;
			}
			if (b == a)
			{
				break;
			}
			void * c = malloc(sizeof(void)*w);
			memcpy(c, base+a*w, w);
			memcpy(base+a*w, base+b*w, w);
			memcpy(base+b*w, c, w);
		}
	}
}
int main()
{
	unsigned long n;
	scanf("%ld\n", &n);
	char s[n][15];
	for (unsigned long i = 0; i < n; i++)
	{
		gets(s[i]);
	}
	hsort(s,n, sizeof(s[0]),compare);
	for (unsigned long i = 0; i < n; i++)
	{
		puts(s[i]);
	}
	return 0;
}
