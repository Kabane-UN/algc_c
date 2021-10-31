#include <stdio.h>
#include <malloc.h>
#include <string.h>
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
    char * c;
    int index = 0;
    c = (char *) malloc(width);
    memcpy(c, base, width);
    for (int i = 1; i < nel; i++)
    {
        if(compare(base+(i*width), c) > 0)
        {
            index = i;
            memcpy(c, base+(i*width), width);
        }
    }
    return index;
}
int compare(void *a, void *b)
{
    return (*(int*)a-*(int *)b);
}
int main()
{
    int array[] = {200000,1232434,3,4};
    printf("%d\n", maxarray(array, 4, sizeof(int), compare));
    return 0;
}
