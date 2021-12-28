#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

typedef char ALIGN[16];

union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next;
    } s; //total_size = header_size + size and call sbrk(total_size)

    ALIGN stub;
};

typedef union header header_t;

pthread_mutex_t global_malloc_lock;

void *malloc(size_t size);
void free(void *block);
void *calloc(size_t num, size_t nsize);
void *realloc(void *block, size_t size);
int abs(const int n);
double atof(const char *__nptr);
int atoi(const char *__nptr);