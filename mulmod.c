#include <stdio.h>
long int foo(long int a, long int b, long int m)
{
    if(b<2)
    {
        return (a*b) % m;
    } else
    {
        return (((b%2)*a)%m+((foo(a,b/2,m))%m)*(2%m))%m;
    }
}
int main()
{
    long int a, b, m,s=0;
    scanf("%ld", &a);
    scanf("%ld", &b);
    scanf("%ld", &m);

    printf("%ld\n", foo(a, b, m));
    return 0;
}
