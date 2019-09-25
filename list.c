# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "list.h"

SINODE *sin_create(int data) {
    SINODE *sinode;
    if ((sinode = (SINODE *) malloc(sizeof(SINODE)))) {
        sinode->data = data;
        sinode->next = NULL;
        return sinode;
    }

    errno = ENOMEM;
    perror("Couldn't allocate memory to list node");
    return NULL;

}

void sin_add(SINODE **head, SINODE *new_node) {
    SINODE *current = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

SINODE *sin_insert(SINODE **head, int data, int pos) {
    SINODE *new_node = sin_create(data);
    SINODE *current = *head;
    if (*head == NULL || pos > sin_length(*head)) {
        sin_add(head, new_node);
        return *head;
    }

    if (pos < 0) {
        new_node->next = *head;
        *head = new_node;
        return *head;
    }

    for (int count = 0; count < pos - 1; count++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return current;
}

int sin_length(SINODE *head) {
    int count = 0;
    while (head != NULL) {
        count = count + 1;
        head = head->next;
    }
    return count;

}

int sin_delete(SINODE **head, int pos) {
    SINODE *current = *head;

    int data = 0;
    if (*head == NULL || pos > sin_length(*head)) {
        errno = EINVAL;
        perror("List index out of bound error");
        return EXIT_FAILURE;
    }

    if(pos == 1){
        data = current->data;
        *head = current->next;
    }else {
        for (int count = 0; count < pos - 2; count++) {
            current = current->next;
        }

        SINODE* temp = current->next;
        data = current->next->data;
        current->next = current->next->next;
        temp->next = NULL;
        free(temp);
    }

    return data;
}

void sin_remove(SINODE **head, int start, int end) {
    SINODE *current = *head;
    if (*head == NULL || (start + end) > sin_length(*head)) {
        errno = EINVAL;
        perror("List index out of bound error");
        return;
    }
    if (end < 0) {
        errno = EINVAL;
        perror("count for deletion cannot be negative!");
        return;
    }
    for (int count = 0; count < start - 2; count++) {
        current = current->next;
    }

    for (int count = 0; count < end; count++) {
        current->next = current->next->next;
    }
}

void sin_remove_element(SINODE** head, int value){
    SINODE* current = *head;
    SINODE* previous;

    if((*head)->data == value){
        previous = *head;

    }

    while(current->next!=NULL){
        if(current->next->data == value){
            previous = current;
        }
        current = current->next;
    }

    if(previous == *head){
        sin_delete(head,1);
    }

    previous->next = previous->next->next;
}

int sin_mid(SINODE** head){
    SINODE* current = *head;
    SINODE* middle = *head;

    while(current!=NULL && current->next!=NULL){
        middle = middle->next;
        current = current->next->next;
    }

    return middle->data;
}

int sin_print(SINODE *curr) {

    int printed_node_count = 0;
    fprintf(stdout, "{ ");
    while (curr != NULL) {
        fprintf(stdout, "%d ", curr->data);
        curr = curr->next;
        printed_node_count = printed_node_count + 1;
    }

    fprintf(stdout, "}");
    return printed_node_count;
}

