#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

struct Elem {
	struct Elem *prev, *next;
	int v;
};
void psort(struct Elem* a , long n)
{
	struct Elem* all = a;
	for (long i = 1; i < n; i++)
	{
		struct Elem* al = all;
		long l = i - 1;
		int e = al->next->v;
		while ((al->v > e) && l >= 0)
		{
			al->next->v = al->v;
			l--;
			al = al->prev;
		}
		al->next->v = e;
		all = all->next;
	}
}
int main()
{
	long n;
	scanf("%ld", &n);
	struct Elem *p;
	struct Elem *pf;
	for (long i = 0; i<n;i++)
	{
		struct Elem *c = malloc(sizeof(struct Elem));
		scanf("%d", &c->v);
		if (i>0)
		{
			c->prev = p;
			p->next = c;
		}
		else
		{
			pf = c;
		}
		p = c;
	}
	p->next = pf;
	pf->prev = p;
	psort(pf, n);
	p = pf;
	for (long i = 0; i<n;i++)
	{
		printf("%d\n", p->v);
		struct Elem* c;
		c= p;
		if (i < n-1) p = p->next;
		free(c);
	}
	return 0;
}
