#include <stdio.h>
int main()
{
    long int n,m;
    scanf("%ld", &n);
    scanf("%ld", &m);
    long int arr[n][m];
    for (long int i=0; i<n;i++)
    {
        for (long int j=0; j<m;j++)
        {
            scanf("%ld", &arr[i][j]);
        }
    }
    long int a[m][2];
    for (long int i=0; i<m;i++)
    {
        a[i][0]=2147483647;
        a[i][1]=-1;
    }
    for (long int i=0; i<n;i++)
    {
        long int c = 0;
        long int k = 0;
        for (long int j=0; j<m;j++)
        {
            long int v = arr[i][j];
            if(v>c)
            {
                c = v;
                k = j;
            }
            if(a[j][0]>v)
            {
                a[j][1]=-1;
                a[j][0]=v;
            }
        }
        if(a[k][0]==c)
        {
            a[k][1]=i;
        }
    }
    for(long int i=0; i<m;i++)
    {
        if(a[i][1] != -1)
        {
            printf("%ld\t%ld\n", a[i][1], i);
            break;
        }
    }
    return 0;
}
