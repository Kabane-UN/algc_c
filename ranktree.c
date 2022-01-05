#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Bstree {
	char *str;
	long k;
	long count;
	struct Bstree *parent;
	struct Bstree *left;
	struct Bstree *right;
};
struct Bstree* mini(struct Bstree* tree)
{
	struct Bstree * res;
	if (tree == NULL)
	{
		res = NULL;
	}
	else
	{
		res = tree;
		while (res->left != NULL)
		{
			res = res->left;
		}
	}
	return res;
}
struct Bstree *suc(struct Bstree* p)
{
	struct Bstree *res;
	if (p->right != NULL)
	{
		res = mini(p->right);
	}
	else
	{
		res = p->parent;
		while ((res != NULL) && (p == res->right))
		{
			p = res;
			res = res->parent;
		}
	}
	return res;
}
struct Bstree *des(struct Bstree* tree, long k)
{
	struct Bstree *p = tree;
	while ((p != NULL) && p->k != k)
	{
		if (k < p->k)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return p;
}
char * look(struct Bstree* tree, long k)
{
	struct Bstree *p = des(tree, k);
	return p->str;
}
struct Bstree * allpeaks[100001];
long allc = 0;
struct Bstree *ins(struct Bstree* tree, long k, char* str)
{
	struct Bstree* new = malloc(sizeof(struct Bstree));
	allpeaks[allc] = new;
	allc++;
	new->k = k;
	new->str = str;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->count = 0;
	if (tree == NULL) tree = new;
	else
	{
		struct Bstree *p = tree;
		while (1)
		{
			if (k<p->k)
			{
				if (p->left == NULL)
				{
					p->left = new;
					p->count++;
					new->parent = p;
					break;
				}
				p->count++;
				p = p->left;
			}
			else
			{
				if (p->right == NULL)
				{
					p->right = new;
					p->count++;
					new->parent = p;
					break;
				}
				p->count++;
				p = p->right;
			}
		}
	}
	return tree;
}
struct Bstree *rpn(struct Bstree *tree, struct Bstree* x, struct Bstree *y)
{
	if (x == tree)
	{
		tree = y;
		if (y != NULL) y->parent = NULL;
	}
	else
	{
		struct Bstree *p = x->parent;
		if (y != NULL)
		{
			y->parent = p;
			p->count = p->count - x->count - 1 + y->count + 1;
		}
		else
		{
			p->count = p->count - x->count - 1;
		}
		if (p->left == x)
		{
			p->left = y;
		}
		else
		{
			p->right = y;
		}
	}
	return tree;
}
char* rang(struct Bstree *tree, long x)
{
	struct Bstree *ptree = tree;
	while (1)
	{
		long pc;
		if (ptree->left == NULL)
		{
			pc = -1;
		}
		else
		{
			pc = ptree->left->count;
		}
		if (pc+1 == x)
		{
			return ptree->str;
		}
		else if (pc>=x)
		{
			ptree = ptree->left;
		}
		else
		{
			ptree = ptree->right;
			x -= pc+2;
		}
	}
}
struct Bstree * del(struct Bstree* tree, long k)
{
	struct Bstree *x = des(tree, k);
	if ((x->left == NULL) && (x->right == NULL))
	{
		tree = rpn(tree, x, NULL);
	}
	else if (x->left == NULL)
	{
		tree = rpn(tree, x, x->right);
	}
	else if (x->right == NULL)
	{
		tree = rpn(tree, x, x->left);
	}
	else
	{
		struct Bstree *y = suc(x);
		tree = rpn(tree, y, y->right);
		x->left->parent = y;
		y->left = x->left;
		if (x->right != NULL)
		{
			x->right->parent = y;
		}
		y->right = x->right;
		y->count = x->count-1;
		tree = rpn(tree, x, y);
	}
	return tree;
}
int main()
{
	long n;
	scanf("%ld\n", &n);
	struct Bstree *tree = NULL;
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
			tree = ins(tree, k, c);
		}
		else if (s[0]=='L' && s[1]=='O' && s[2]=='O' && s[3]=='K' && s[4]=='U' && s[5]=='P')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			puts(look(tree, k));
		}
		else if (s[0]=='D' && s[1]=='E' && s[2]=='L' && s[3]=='E' && s[4]=='T' && s[5]=='E')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			tree = del(tree, k);
		}
		else
		{
			char then[100] = " ";
			strtok(s, then);
			long x = strtol(strtok(NULL, then), NULL, 10);
			puts(rang(tree, x));
		}
	}
	for (long i = 0; i<allc;i++)
	{
		free(allpeaks[i]->str);
		free(allpeaks[i]);
	}
	return 0;
}
