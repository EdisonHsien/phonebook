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


unsigned int BKDRHash(char *str)
{
    unsigned int seed = 31;
    unsigned int hash = 0;

    while(*str)
        hash = hash * seed + (*str++);


    return (hash % MAX_TABLE_SIZE);

}
