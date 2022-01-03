#include <unistd.h>
#include <signal.h>
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

typedef struct {
    int quot;
    int rem;
}div_t;

typedef struct {
    long quot;
    long rem;
}ldiv_t;

pthread_mutex_t global_malloc_lock;

/* Memory Control Functions */
/* ===================================================================================== */
void *malloc(size_t size); //memory allocation
void free(void *block); //memory release
void *calloc(size_t num, size_t nsize); //memory reset
void *realloc(void *block, size_t size); //memory resize

/* essence functions */
/* ===================================================================================== */
int abs(const int n); /* absoulte sequence (int)*/
div_t div(const int __num, const int __div); /* divide num (int) */
long labs(const long n); /* absolute sequence (long) */
ldiv_t ldiv(const long __num, const long __div); /* divide num (long) */

/* character control functions */
/* ===================================================================================== */
double atof(const char *__nptr); //char to double
int atoi(const char *__nptr); //char to int
long atol(const char *__nptr); //char to long
double strtod(const char *__nptr, const char **__endptr); //char to double & divide char
long int strtol(const char *__nptr, const char **__endptr); //char to long & divide char
unsigned long int stroul(const char *__nptr, const char **__endptr); //char to unsigned long & divide char

/* search and sorting functions */
/* ===================================================================================== */
void *bsearch();  //array binary search
void qsort(); // array element quick sort

/* random number generate functions */
/* ===================================================================================== */
int rand(void); // random value generate
int srand(unsigned int __seed); // clear for generate random value

/* execute functions */
/* ===================================================================================== */
void abort(void); // this process exit
int atexit(void (*function) (void)); // specified function excute as exit
void exit(int status); // call process exit
char *getenv(const char *name); // get system enviorment string
int system(const char *command); // execute system command