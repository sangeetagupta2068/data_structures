//
// Created by SANGEETA GUPTA on 2019-09-05.
//
/*
 * si_list.c - Ane api to provide basic functions to create, read, write and process a list of integers.
 *
 * author - Harshad Gune, harshad.gune@gmail.com
 * version - 1.0, August 31, 2019
 */

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "list.h"

/* sin_create(): Creates a new list node, if successuful returns the address of the new node.
 * On error returns NULL and sets the errorno to ENOMEM.
 */
SINODE *sin_create(int data) {

    SINODE sinode;
    sinode.data = data;
    sinode.next = NULL;

    return &sinode;

}

/* sin_add(): Adds a node at the end of existing list.
// */
void sin_add(SINODE **head, SINODE *new_node) {
//     Code to add a node at the end of exisiting list.
//     Note: The list may be empty initially

    SINODE *current = *head;
    if(*head == NULL){
        *head = new_node;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}
//
///* sin_insert(): Creates a node with specified data and inserts it in the list at specified position and
// * returns the address of inserted node. pos = 0 signifies the first node.
// * A 0 or negative value of pos will insert the node at first position.
// * A value of pos, greater than the length will insert the node at the end.
// * On error, returns NULL and the errorno is set to ENOMEM
// */

SINODE *sin_insert(SINODE **head, int data, int pos) {
    // List is empty, new node is added as first node.
    // List is not empty, new node is inserted at first position.
    // New node is inserted beyond first node.
    SINODE *temp_node;
    SINODE *current = *head;
    if(*head == NULL){
        *head = sin_create(data);
        return *head;
    }

    for(int count = 0; count<pos -1 && current->next!=NULL;count++){
        fprintf(stdout,"%d",count);
        current = current->next;
    }

    temp_node = current->next;
    fprintf(stdout,"\ntemporary node: %d",temp_node->data);
    fprintf(stdout,"\nnew node: %d",current->next->data);
    current= sin_create(data);
    fprintf(stdout,"\nnew node: %d",current->data);
    return current;
}

/* sin_delete(): Deletes the node at specified position. Returns the data from the deleted node.
 */
//int sin_delete(SINODE **head, int pos) {
//
//}
//
///* sin_length(): Returns the number of nodes in the list.
// */
//int sin_length(SINODE *head) {
//    // Code to count the number of nodes in the list.
//}
//
/* sin_print(): Print the list from specified node, returns the number of nodes printed */
int sin_print(SINODE *curr) {

    int printed_node_count = 0;
    fprintf(stdout,"{ ");
    while (curr != NULL) {
        fprintf(stdout, "%d ", curr->data);
        curr = curr->next;
        printed_node_count = printed_node_count+1;
    }

    fprintf(stdout,"}");
    return printed_node_count;
    // Code to print the value (date) of nodes in the list.
}

//
