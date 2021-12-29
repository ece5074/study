#include "essenceTest.h"
#include <mystdlib.h>

void essenceTest()
{
    int rxt;

    rxt = absTest();
    if(rxt >= 0)
    {
        fprintf(stdout, "[absTest] %s\n", SUCCESS);
    }

    rxt = divTest();
    if(rxt > 0)
    {
        fprintf(stdout, "[divTest] %s\n", SUCCESS);
    }

    rxt = labsTest();
    if(rxt >= 0)
    {
        fprintf(stdout, "[labsTest] %s\n", SUCCESS);
    }

    rxt = ldivTest();
    if(rxt >= 0)
    {
        fprintf(stdout, "[ldivTest] %s\n", SUCCESS);
    }
}

int absTest()
{
    int rxt;
    rxt = abs(-2147483647);
    if(rxt != 2147483647)
    {
        log(FAIL, rxt);
        return -1;
    }

#if 1
    rxt = abs(-2147483648);
    if(rxt != -2147483648)
    {
        log(FAIL, rxt);
        return -1;
    }
#endif
    return 1;
}

int divTest()
{
    div_t rxt;
    rxt = div(13, 5);
    if(rxt.quot != 2 && rxt.rem != 3)
    {
        log(FAIL, rxt.quot);
        log(FAIL, rxt.rem);
        return -1;
    }

    rxt = div(2147483647, 2147483646);
    if(rxt.quot != 1 && rxt.rem != 1)
    {
        log(FAIL, rxt.quot);
        log(FAIL, rxt.rem);
        return -1;
    }

    rxt = div(2147483647, -2147483648);
    if(rxt.rem != 2147483647);
    {
        if(!rxt.quot) return 1;
        log(FAIL, rxt.quot);
        log(FAIL, rxt.rem);
        return -1;
    }

    return 1;
}

int labsTest()
{
    long rxt;
    
    rxt = labs(-2147483648);
    if(rxt != 2147483648)
    {
        log(FAIL, rxt);
        return -1;
    }

#if 1
    rxt = labs(__LONG_MAX__ * (-1) - 1);
    if(rxt != __LONG_MAX__ * (-1) - 1)
    {
        log(FAIL, rxt);
        return -1;
    }
#endif
    return 1;
    return 1;
}

int ldivTest()
{
    ldiv_t rxt;
    rxt = ldiv(13, 5);
    if(rxt.quot != 2 && rxt.rem != 3)
    {
        log(FAIL, rxt.quot);
        log(FAIL, rxt.rem);
        return -1;
    }

    rxt = ldiv(9223372036854775807L, 9223372036854775806L);
    if(rxt.quot != 1 && rxt.rem != 1)
    {
        log(FAIL, rxt.quot);
        log(FAIL, rxt.rem);
    }
    return 1;
}