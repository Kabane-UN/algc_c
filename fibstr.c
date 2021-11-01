#include <stdio.h>
#include <malloc.h>

char *fibstr(int n)
{
    char * s1 = malloc(sizeof(char)*2);
    char * s2 = malloc(sizeof(char)*2);
	unsigned long int l1 = 2, l2 = 2;
    *s1 = 'a';
	s1[1] = 0;
    *s2 = 'b';
	s2[1] = 0;
    switch (n)
    {
        case 1:
			free(s2);
            return s1;
        case 2:
			free(s1);
            return s2;
        default:
            for (int i = 2; i < n; i++)
            {
				unsigned long int lc = l1;
				char *c = malloc(sizeof(char)*(l1+l2-1));
				for (int j = 0; j < l1-1; j++)
				{
					c[j] = s1[j];
				}
				free(s1);
				for (int j = 0; j < l2; j++)
				{
					c[l1-1+j] = s2[j];
				}
				s1=s2;
				l1=l2;
				s2=c;
				l2=lc+l2-1;
            }
			free(s1);
			return s2;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
	char * s = fibstr(n);
    puts(s);
}
