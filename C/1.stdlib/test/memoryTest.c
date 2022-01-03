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
    free(a);
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