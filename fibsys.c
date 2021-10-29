#include <stdio.h>
int main()
{
    long int a, r=0, i;
    scanf("%ld", &a);
    while (a > 0)
    {
        long int b=1, b1=1;
        i=0;
        while (b1<a)
        {
            long int c=b+b1;
            b=b1;
            b1=c;
            i++;
        }
        if (b1==a)
        {
            a-=b1;
            i+=1;
        } else
        {
            a-=b;
        }
        if(r!=0)
        {
            for (long int j = 0; j < (r-i-1); j++)
            {
                printf("%d", 0);
            }
            printf("%d", 1);
        } else
        {
            printf("%d", 1);
        }
        r=i;
    }
    if (i > 1)
    {
        for (long int j = 0; j < i-1; j++)
        {
            printf("%d", 0);
        }
    }
    return 0;
}
