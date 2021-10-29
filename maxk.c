#include <stdio.h>
int main()
{
    long int n,k,s=0,m;
    scanf("%ld", &n);
    long int arr[n];
    for (long int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    scanf("%ld", &k);
    for (long int i = 0; i < n; i++)
    {
        if(i<k)
        {
            s+=arr[i];
            if (i==k-1)
            {
                m=s;
            }
        } else
        {
            s = s + arr[i] - arr[i-k];
            if (s>m)
            {
                m = s;
            }
        }
    }
    printf("%ld\n", m);
    return 0;
}
