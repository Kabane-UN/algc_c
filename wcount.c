#include <stdio.h>
#include <malloc.h>

int wcount(char *s)
{
    int k = 0;
    unsigned long i = 0;
    int f = 0;
    while (1)
    {
        switch (s[i])
        {
            case 0:
                if (f)
                {
                    k++;
                }
                goto end;
            case ' ':
                if(f)
                {
                    k++;
                }
                f = 0;
                break;
            default:
                f = 1;
        }
        i++;
    }
    end:;
    return k;
}
int main()
{
    char * arr= malloc(100*sizeof(char));
    gets(arr);
    printf("%d\n", wcount(arr));

}
