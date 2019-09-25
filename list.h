# ifndef SI_LIST_H
# define SI_LIST_H

typedef struct slnode {
    int data;
    struct slnode* next;
} SINODE;

SINODE* sin_create(int data);

void sin_add(SINODE** head, SINODE* new_node);

SINODE* sin_insert(SINODE** head, int data, int pos);

int sin_delete(SINODE** head, int pos);

int sin_mid(SINODE** head);

int sin_length(SINODE* head);

int sin_print(SINODE* curr);

void sin_remove(SINODE** head,int start, int end);

void sin_remove_element(SINODE** head, int value);

# endif

