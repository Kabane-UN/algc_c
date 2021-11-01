#include <stdio.h>
#include <string.h>

struct Elem {
	enum {
		INTEGER,
		FLOAT,
		LIST
	} tag;

	union {
		int i;
		float f;
		struct Elem *list;
	} value;

	/* Указатель на «хвост» списка */
	struct Elem *tail;
};
struct Elem  *searchlist(struct Elem  *list, int k)
{
	switch (list->tag)
	{
		case INTEGER:
			if (k==list->value.i)
			{
				return list;
			}
			return (list->tail==NULL)?NULL:searchlist(list->tail, k);
		case FLOAT:
			return (list->tail==NULL)?NULL:searchlist(list->tail, k);
		case LIST:
			;
			struct Elem * v = searchlist(list->value.list, k);
			return (v != NULL)?v:(list->tail==NULL)?NULL:searchlist(list->tail, k);
	}
}
int main()
{
	struct Elem s,t,l,b,e;
	s.tag=INTEGER;
	s.value.i=3;
	s.tail=&t;
	t.tag=LIST;
	t.value.list=&l;
	t.tail=&e;
	l.tag=FLOAT;
	l.value.f=(float)12.3;
	l.tail=&b;
	b.tag=INTEGER;
	b.value.i=10;
	b.tail=NULL;
	e.tag=INTEGER;
	e.value.i=3;
	e.tail=NULL;
	printf("%p\n", searchlist(&s,5));
	return 0;
}
