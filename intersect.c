#include <stdio.h>
#include <math.h>
int main()
{
    long int a=0, b = 0,na,nb,per;
    scanf("%ld", &na);
    for (long int i=0; i<na; i++)
    {
        int c=0;
        scanf("%d", &c);
        a += (long int) pow(2, c);
    }
    scanf("%ld", &nb);
    for (long int i=0; i<nb; i++)
    {
        int c=0;
        scanf("%d", &c);
        b += (long int) pow(2, c);
    }
    per = a&b;
    long int i =0;
    while (per>0)
    {
        if(per%2==1)
        {
            printf("%ld\n", i);
        }
        per/=2;
        i++;
    }
    return 0;
}
