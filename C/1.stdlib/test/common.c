#include "common.h"

void macro_log(const char *func, int line, const char *msg, long long ret)
{
    printf("[%s:%d] %s, result: [%lld]\n", func, line, msg, ret);
}