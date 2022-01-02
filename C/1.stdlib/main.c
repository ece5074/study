#include "test/common.h"
#include "test/memoryTest.h"
#include "test/stringTest.h"
#include "test/essenceTest.h"

/*

*/

int main(void)
{
    stringTest();
    essenceTest();
    memoryTest();
    return 1;
}