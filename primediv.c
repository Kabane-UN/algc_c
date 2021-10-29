#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    long int a;
    scanf("%ld", &a);
    if(a<0)
    {
        a = -a;
    }
    long int *arr= (long int*)malloc((a+1)*sizeof(long int));
    for (long int i = 0; i < a+1;i++)
    {
        arr[i]=i;
    }
    arr[1]=0;
    long int i = 2;
    while (i <= a)
    {
        if (arr[i] != 0)
        {
            long int j = i*2;
            while( j <= a)
            {
                arr[j] = 0;
                j += i;
            }
        }
        i++;
    }
    for (long int j = a; j >= 0;j--)
    {
        if (arr[j] != 0 && a%arr[j]==0)
        {
            printf("%ld\n", arr[j]);
            break;
        }
    }
    return 0;
}
