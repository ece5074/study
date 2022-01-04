#include "stringTest.h"

void stringTest()
{
    int rxt;
    rxt = atoiTest();

    //rxt 0인 경우에만 실패처리하게끔 하였음
    if(rxt)
    {
        fprintf(stdout, "[atoi] %s\n", SUCCESS);
    }

    rxt = atofTest();
    if(rxt)
    {
        fprintf(stdout, "[atof] %s\n", SUCCESS);
    }

    rxt = atolTest();
    if(rxt)
    {
        fprintf(stdout, "[atol] %s\n", SUCCESS);
    }

    rxt = strtodTest();
    if(rxt)
    {
        fprintf(stdout, "[strtod] %s\n", SUCCESS);
    }
}


//BUG 테스트를 위해 -2147483648은 atoi로 변환되지않음 (실질 범위 -2147483647 ~ 2147483647)
int atoiTest()
{
    int ret = 0;
    char *str;

    str = "a";
    ret = atoi(str);
    if(ret != 0){
        log(FAIL, ret);
        return 0;
    }

    str = "                         -2147483649"; //negative INT OVERFLOW
    ret = atoi(str);
    if(ret != 0){
        log(FAIL, ret);
        return 0;
    } 
    
    str = " +2147483648";          // positive INT OVERFLOW
    ret = atoi(str);
    if(ret != 0){
        log(FAIL, ret);
        return 0;
    } 

    str = "2147483647";            //INT MAX
    ret = atoi(str);
    if(ret != __INT_MAX__){
        log(FAIL, ret);
        return 0;
    } 

#if 1
    str = "-2147483648"; // negative INT MAX
    ret = atoi(str);
    if(ret != __INT_MAX__ * (-1) -1){
        log(FAIL, ret);
        return 0;
    }
#endif

#if 0
    str = "-2147483647";
    ret = atoi(str);
    if(ret != __INT_MAX__ * (-1)){
        log(FAIL, ret);
        return 0;
    }
#endif

    return ret;
}

int atofTest()
{
    double ret = 0;
    char *str;

    str = "a";
    ret = atof(str);
    if(ret != 0.000f)
    {
        log(FAIL, ret);
        return 0;
    }

    str = "21.47483647";
    ret = atof(str);
    if(ret != 21.47483647)
    {
        log(FAIL, ret);
        return 0;
    }

    str = "-21.47483647";
    ret = atof(str);
    if(ret != -21.47483647)
    {
        log(FAIL, ret);
        return 0;
    }

    return 1;
}

int atolTest()
{
    long ret = 0;
    char *str;

    str = "a";
    ret = atol(str);
    if(ret != 0)
    {
        log(FAIL, ret);
        return 0;
    }

    str = "                   -19485717263654185";
    ret = atol(str);
    if(ret != -19485717263654185L)
    {
        log(FAIL, ret);
        return 0;
    }

    str = "             92233720368547 75807";
    ret = atol(str);
    if(ret != 92233720368547)
    {
        log(FAIL, ret);
        return 0;
    }

    str = "   9223372036854775807";
    ret = atol(str);
    if(ret != __LONG_MAX__)
    {
        log(FAIL, ret);
        return 0;
    }

    str = "   -9223372036854775808";
    ret = atol(str);
    if(ret != -9223372036854775808UL)
    {
        log(FAIL, ret);
        return 0;
    }

    return 1;
}

int strtodTest()
{
    char *retstr;
    double ret;

    char *str;

    retstr = malloc(sizeof(500));

    str = "     -92.222451 abcded";
    ret = strtod(str, &retstr);
    if(ret != -9222.222451f && strncmp(retstr, "abcded", 6))
    {
        log(FAIL, ret);
        printf("retstr: %s\n", retstr);
        return 0;
    }

    return 1;
}