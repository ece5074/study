#include "test/common.h"
#include "test/memoryTest.h"
#include "test/stringTest.h"
#include "test/essenceTest.h"

/*

*/

void helloworld(void)
{
    printf("Hello World!!\n");
}

void byeworld(void)
{
    printf("bye World!!\n");
}

int main(void)
{
    printf("Start Test pid: [%d]\n", getpid());
    atexit(helloworld);
    atexit(byeworld);
    stringTest();
    essenceTest();
    memoryTest();
    return 1;
}