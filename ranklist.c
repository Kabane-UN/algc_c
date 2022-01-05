#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Slist {
	char *str;
	long k;
	long *span;
	struct Slist **next;
};
struct Slist * suc(struct Slist * list)
{
	return list->next[0];
}
struct Slist ** scip(struct Slist * list, long m, long k, struct Slist **p)
{
	struct Slist * r = list;
	for (long i = m -1; i>=0;i--)
	{
		while ((r->next[i] != NULL) && r->next[i]->k < k)
		{
			r = r->next[i];
		}
		p[i] = r;
	}
	return p;
}
char * look(struct Slist *list, long m, long k)
{
	struct Slist ** p = malloc(sizeof(struct Slist*)*m);
	scip(list, m, k, p);
	struct Slist * r = suc(p[0]);
	free(p);
	return r->str;
}
struct Slist * ins(struct Slist * list, long m, long k, char* c)
{
	struct Slist ** p = malloc(sizeof(struct Slist*)*m);
	scip(list, m, k, p);
	struct Slist *new = malloc(sizeof(struct Slist));
	new->next = malloc(sizeof(struct Slist *)*m);
	new->span = malloc(sizeof(long)*m);
	new->str = c;
	new->k = k;
	srand(time(NULL));
	long r = (long) rand()*2;
	long i = 0;
	while ((i < m) && (r%2==0))
	{
		new->next[i] = p[i]->next[i];
		p[i]->next[i] = new;
		if (i == 0)
		{
			new->span[i] = 1;
			if (new->next[i] == NULL) new->span[i] = 0;
			p[i]->span[i] = 1;
			if (p[i]->next[i] == NULL) p[i]->span[i] = 0;
		}
		else
		{
			struct Slist * e = p[i];
			long count = 0;
			while (e != new)
			{
				e = e->next[0];
				count++;
			}
			long cp = p[i]->span[i];
			p[i]->span[i] = count;
			new->span[i] = cp-count+1;
			if (cp == 1 == count) new->span[i] = 1;
			if (new->next[i] == NULL) new->span[i] = 0;
			if (p[i]->next[i] == NULL) p[i]->span[i] = 0;
		}
		i++;
		r /= 2;
	}
	for (long j = i; j < m; j++)
	{
		new->next[j] = NULL;
		new->span[j] = 0;
		if (p[j]->next[j] != NULL) p[j]->span[j]++;
	}
	free(p);
}
struct Slist * del(struct Slist * list, long m, long k)
{
	struct Slist ** p = malloc(sizeof(struct Slist*)*m);
	scip(list, m, k, p);
	struct Slist *res = suc(p[0]);
	long i = 0;
	while ((i < m) && (p[i]->next[i] == res))
	{
		p[i]->next[i] = res->next[i];
		if (p[i]->next[i] == NULL) p[i]->span[i] = 0;
		else p[i]->span[i] = p[i]->span[i] + res->span[i] - 1;
		i++;
	}
	for (long j = i; j < m; j++)
	{
		if (p[j]->next[j] != NULL) p[j]->span[j]--;
	}
	free(p);
	return res;
}
long rang(struct Slist * list, long m, long k)
{
	struct Slist* e = list;
	long counter = 0;
	struct Slist* le = e;
	for (long i = m-1; i>=0;i--)
	{
	loop:;
		if (e->next[i] != NULL)
		{
			if (e->str == NULL && e->next[i]->k <= k)
			{
				counter += e->span[i] - 1;
			}
			else if (e->k < k && e->str != NULL)
			{
				counter += e->span[i];
			}
			else if (e->k == k)
			{
				return counter;
			}
			else
			{
				e = le;
				continue;
			}
			le = e;
			e = e->next[i];
			goto loop;
		}
		else
		{
			if (e->k < k)
			{
				continue;
			}
			else if (e->k == k)
			{
				return counter;
			}
			else
			{
				e = le;
				continue;
			}
		}
	}
}
int main()
{
	long n;
	scanf("%ld\n", &n);
	struct Slist *first = malloc(sizeof(struct Slist));
	long m = (long) log2((double )n)+1;
	first->next = malloc(sizeof(struct Slist *)*m);
	first->span = malloc(sizeof(long)*m);
	first->str = NULL;
	first->k = -1000000000;
	for (long j = 0; j < m; j++)
	{
		first->next[j] = NULL;
		first->span[j] = 0;
	}
	for (long i = 0; i < n; i++)
	{
		char s[25];
		gets(s);
		if (s[0]=='I' && s[1]=='N' && s[2]=='S' && s[3]=='E' && s[4]=='R' && s[5]=='T')
		{

			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			char *c = malloc(sizeof(char)*100);
			strcpy(c, strtok(NULL, then));
			ins(first, m, k, c);
		}
		else if (s[0]=='L' && s[1]=='O' && s[2]=='O' && s[3]=='K' && s[4]=='U' && s[5]=='P')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			puts(look(first, m, k));
		}
		else if (s[0]=='D' && s[1]=='E' && s[2]=='L' && s[3]=='E' && s[4]=='T' && s[5]=='E')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			struct Slist *c = del(first, m, k);
			free(c->next);
			free(c->span);
			free(c->str);
			free(c);
		}
		else
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			printf("%ld\n", rang(first, m, k));
		}
		/*
		for (long j = 0; j<m; j++)
		{
			struct Slist *e = first;
			while (e != NULL)
			{
				printf("(%ld %s %ld) ", e->k, e->str, e->span[j]);
				e = e->next[j];
			}
			printf("\n");
		}
		 */
	}
		struct Slist *e = first;
		while (e != NULL)
		{
			struct Slist * c = e;
			e = e->next[0];
			free(c->span);
			free(c->next);
			free(c->str);
			free(c);
		}
	return 0;
}
