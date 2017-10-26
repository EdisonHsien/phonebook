#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
//    char firstName[16];
//    char email[16];
//    char phone[10];
//    char cell[10];
//    char addr1[16];
//    char addr2[16];
//    char city[16];
//    char state[2];
//    char zip[5];
    char *firstName_ptr;
    char *email;
    char *phone;
    char *cell;
    char *addr1;
    char *addr2;
    char *city;
    char *state;
    char *zip;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

struct node {
    int data;
    struct node *left;
    struct node *right;
} treeNode;

typedef struct Memory_pool {
    char *next;
    char *head;
    char *tail;
} m_pool;



entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
