#include <stdio.h>
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long rnel = nel;
    unsigned long nu = 0;
    while (1)
    {
        switch (compare((nu+nel)/2))
        {
            case 1:
                if (nel == (nu+nel)/2) return rnel;
                nel=(nu+nel)/2;
                break;
            case -1:
                if (nu == (nu+nel)/2) return rnel;
                nu=(nu+nel)/2;
                break;
            default:
                goto end;
        }
    }
    end:
    return (nu+nel)/2;
}
int array[5] = {1,2,4,5,6};

int compare(unsigned long i)
{
    if(array[i]>5)
    {
        return 1;
    } else if (array[i]<5)
    {
        return -1;
    } else
    {
        return 0;
    }
}
int main()
{
    printf("%ld\n", binsearch(5, compare));
    return 0;
}
