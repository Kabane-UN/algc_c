#include <stdio.h>
unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
    if (nel == 1 || less(1,0)) return 0;
    if (less(nel-2,nel-1)) return nel-1;
    for (unsigned long i = 1; i < nel-1;i++)
    {
        if (less(i-1,i) && less(i+1,i)) return i;
    }
}
int array[] = {1,2,3};

int less(unsigned long i, unsigned long j)
{
    return (array[i]<array[j])?1:0;
}
int main()
{
    printf("%ld\n", peak(3, less));
    return 0;
}
