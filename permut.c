#include <stdio.h>
int main()
{
    int a[8],b[8],c[8]={-1,-1,-1,-1,-1,-1,-1,-1};
    for(int i=0;i<8;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=0;i<8;i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if ((a[i]==b[j]) && (c[j]==-1))
            {
                c[j]=j;
            }
        }
    }
    int f = 1;
    for (int i=0;i<8;i++)
    {
        if (c[i]==-1)
        {
            f = 0;
        }
    }
    if(f)
    {
        printf("%s\n", "yes");
    } else
    {
        printf("%s\n", "no");
    }
    return 0;
}
