#include <stdio.h>
#include <malloc.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
    for (size_t i = 0, j = nel-1; i < j; i++,j--)
    {
        char * c;
        c = (char *) malloc(width);
        memcpy(c, base+(i*width), width);
        memcpy(base+(i*width),base+(j*width), width);
        memcpy(base+(j*width), c, width);
        free(c);
    }
}
int main()
{
    int array[4] = {1,2,3,4};
    revarray(array, 4, sizeof(int));
    for (int i = 0; i<4;i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}
