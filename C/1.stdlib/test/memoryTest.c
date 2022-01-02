#include "memoryTest.h"
#include <mystdlib.h>

void memoryTest()
{
    mallocTest();
}

int mallocTest()
{
    int *a = malloc(5);
    a[5] = 20;

    printf("%d\n", a[5]);
    free(a);
    printf("%d\n", a[5]); 
    return 1;
}

int reallocTest()
{
    return 1;
}

int callocTest()
{
    return 1;
}