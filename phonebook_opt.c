#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_opt.h"

#define MAX_TABLE_SIZE  1024 //Depend on L1 Cache size

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    while(pHead != NULL) {
        if(strcasecmp(lastName, pHead -> lastName) == 0)
            return pHead;
        pHead = pHead -> pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e-> pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}


unsigned int BKDRHash(char lastName[])
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    int i = 0;

    while(i<strlen(lastName)) {
        hash = hash * seed +lastName[i];
        i++;

    }
    return (hash & 0x7FFFFFFF) % MAX_TABLE_SIZE;
}

entry *findName_Hash(char lastName[], entry *pHead)
{

    unsigned int n = BKDRHash(lastName);
    n %= MAX_TABLE_SIZE;
    entry *tmp;
    if(pHead[n]->pNext)
        tmp = pHead[n]->pNext;
    else
        return NULL;
    while(tmp) {
        if(strcasecmp(lastName, tmp->lastName) = 0)
            return tmp;
        tmp = tmp -> pNext;
    }
    return NULL;
}

m_pool *pool_allocate(int size)
{
    m_pool *pool = (m_pool *)malloc(sizeof(m_pool));
    pool->head = pool->next = (char *)calloc(1,size);
    pool ->tail = pool->head +size;
    return pool;
}


void *pool_access(m_pool *pool, int size)
{
    if(pool->tail - pool->next <size)
        return NULL;

    void *tmp = pool->next;
    pool->next = pool->next + size;
    return tmp;
}


void free_list(entry *e)
{
    entry *tmp;
    while((tmp = e) != NULL) {
        e = e->pNext;
        free(tmp);
    }
}

