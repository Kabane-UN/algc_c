#include <stdio.h>
#include <malloc.h>

char *concat(char **s, int n)
{
    unsigned long k = 0;
    char * ns = malloc(sizeof(char));
    if (k>0)
    {
        make:;
        char * gns = malloc(sizeof(char)*(k+2));
        for (int i = 0; i < k;i++)
        {
            gns[i]=ns[i];
        }
        ns=gns;
        goto re;
    }
    for (unsigned long i = 0; i < n;i++)
    {
        unsigned long j = 0;
        while (1)
        {
            switch (s[i][j])
            {
                case 0:
                    goto end;
                default:
                    goto make;
                    re:
                    ns[k] = s[i][j];
                    k++;
            }
            j++;
        }
        end:;
    }
    ns[k]=0;
    return ns;
}
int main()
{
    int n;
    scanf("%d\n", &n);
    char ** arr= malloc(n*sizeof(char*));
    for(int i = 0; i < n;i++)
    {
        arr[i] = malloc(100*sizeof(char));
        gets(arr[i]);
    }
    char *str = concat(arr, n);
    puts(str);
    return 0;
}
