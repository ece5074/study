#include <stdio.h>

#define FAIL "Failed to Test"
#define SUCCESS "Success to Test"
#define log(x, y) macro_log(__func__, __LINE__, x, y)

void macro_log(const char *func, int line, const char *msg, long long ret);