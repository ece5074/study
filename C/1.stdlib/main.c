#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>


/*
        sbrk(0) 현재 program break 위치를 void *형 으로 반환
        sbrk(x) program break를 size만큼 증가
        sbrk(-x) program break를 size만큼 감소

        성공 시, 이전 program break 반환
        실패 시, sbrk()는 (void *) -1을 반환 
*/

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
header_t *head, *tail;
pthread_mutex_t global_malloc_lock;

/* 연결 목록 탐색 후 주어진 크기를 수용할 수 있는 메모리 블록이 존재하는지 확인 */
header_t *get_free_block(size_t size)
{
    header_t *curr = head;
    while(curr) {
        if(curr->s.is_free && curr->s.size >= size)
        {
            return curr;
        }

        curr = curr->s.next;
    }

    return NULL;
}

void *malloc(size_t size)
{
    size_t total_size;
    void *block;
    header_t *header;

    if(!size) return NULL; //요청한 크기가 0인지 확인

    pthread_mutex_lock(&global_malloc_lock);

    header = get_free_block(size); 
    if(header) {
        header->s.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void *) (header + 1);
    }

    total_size = sizeof(header_t) + size;
    //size만큼 힙 확장
    block = sbrk(total_size);
    
    if(block == (void *) -1) {
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;
    }

    header = block;
    header->s.size = size;
    header->s.is_free = 0;
    header->s.next = NULL;

    if(!head)
        head = header;
    if (tail)
        tail->s.next = header;

    tail = header;
    pthread_mutex_unlock(&global_malloc_lock);
    return (void *)(header + 1);
}

void free(void *block)
{
    header_t *header, *tmp;
    void *program_break;

    if(!block) return;
    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t *)block - 1;

    program_break = sbrk(0);
    printf("%d %d %d %d\n", (char *)block, header->s.size, program_break, sizeof(header_t));

    if((char *)block + header->s.size == program_break)
    {
        if(head == tail) {
            head = tail = NULL;
        }
        else
        {
            tmp = head;
            while(tmp) {
                if(tmp->s.next == tail)
                {
                    tmp->s.next = NULL;
                    tail = tmp;
                }

                tmp = tmp->s.next;
            }
        }

        sbrk(0 - header->s.size - sizeof(header_t));
        pthread_mutex_unlock(&global_malloc_lock);
        return ;
    }

    header->s.is_free = 1;
    pthread_mutex_unlock(&global_malloc_lock);
}

//메모리 할당 후 0으로 초기화
void *calloc(size_t num, size_t nsize)
{
    size_t size;
    void *block;

    if(!num || !nsize) return NULL;

    size = num * nsize;

    /* num * nsize가 unsigned long 타입 MAX값을 초과했는지 확인 */
    if(nsize != size / num) return NULL;
    block = malloc(size);
    if(!block) return NULL;

    memset(block, 0, size);
    return block;
}

void *realloc(void *block, size_t size)
{
    header_t *header;
    void *ret;
    if(!block || !size) return malloc(size);
    header = (header_t *)block - 1;
    if(header->s.size >= size)
    {
        return block;
    }

    ret = malloc(size);
    if(ret) {
        memcpy(ret, block, header->s.size);
        free(block);
    }

    return ret;
}