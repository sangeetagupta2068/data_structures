#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    int data;
    SINODE **head;
    *head = NULL;

    fprintf(stdout, "\nEnter the data member:");
    fscanf(stdin, "%d", &data);

    SINODE sinode1 = *(sin_create(data));
    sin_add(head, &sinode1);

    fprintf(stdout, "\nEnter the data member:");
    fscanf(stdin, "%d", &data);

    SINODE sinode2 = *(sin_create(data));
    sin_add(head, &sinode2);

    fprintf(stdout, "\nEnter the data member:");
    fscanf(stdin, "%d", &data);

    SINODE sinode3 = *(sin_create(data));
    sin_add(head, &sinode3);

    fprintf(stdout, "\nEnter the data member:");
    fscanf(stdin, "%d", &data);

    SINODE sinode4 = *(sin_create(data));
    sin_add(head, &sinode4);

    fprintf(stdout, "\nEnter the data member:");
    fscanf(stdin, "%d", &data);

    SINODE sinode6 = *(sin_create(data));
    sin_add(head, &sinode6);

    sin_insert(head,10,3);

//
    SINODE *current = *head;
    sin_print(current);
    return EXIT_SUCCESS;
}