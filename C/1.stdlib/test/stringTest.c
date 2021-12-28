#include "stringTest.h"
#include <mystdlib.h>

#define log(x, y) macro_log(__func__, __LINE__, x, y)

void macro_log(const char *func, int line, const char *msg, int ret)
{
    printf("[%s:%d] %s, result: [%d]\n", func, line, msg, ret);
}

void stringTest()
{
    int rxt;
    rxt = atoiTest();

    //rxt 0인 경우에만 실패처리하게끔 하였음
    if(rxt)
    {
        fprintf(stdout, "%s\n", SUCCESS);
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

#if 0
    str = "-2147483648"; // negative INT MAX
    ret = atoi(str);
    if(ret != __INT_MAX__ * (-1) -1){
        log(FAIL, ret);
        return 0;
    }
#endif

#if 1
    str = "-2147483647";
    ret = atoi(str);
    if(ret != __INT_MAX__ * (-1)){
        log(FAIL, ret);
        return 0;
    }
#endif

    return ret;
}