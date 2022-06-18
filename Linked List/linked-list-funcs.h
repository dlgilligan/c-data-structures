#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node * next;
    int value;
} Node;

// Creates a node 
Node * createNode(int value) {
    Node * nd = malloc(sizeof(Node));
    nd -> next = NULL;
    nd -> value = value;

    return nd;
}

// Add node to the beginning of the list
Node * addNodeFront(Node * head, int val) {
    Node * new = createNode(val);
    new -> next = head;
    return new;
}

// Add node to the end of the list 
void addNodeEnd(Node * head, int val) {
    Node * new = createNode(val);

    Node * temp = head;
    while( (temp -> next) != NULL) {
        temp = temp -> next;
    }
    temp -> next = new;

}

// Prints the entire linked list
void printList(Node * head) {
    Node * temp = head;

    printf("[ ");
    while(temp != NULL) {
        printf("%d ",temp -> value);
        temp = temp -> next;
    }
    printf("]");
}

//Creates a linked list from 1 - n
Node * createList(int n) {
    if( n <= 0) { return NULL; }
    
    Node * head = createNode(1);
    if(n == 1) { return head; }

    Node * temp = head;
    for(int i = 2; i < n + 1; i++) {
        Node * new = createNode(i);
        temp -> next = new;
        temp = temp -> next;
    }

    return head;
}

/*

    ALL FUNCTIONS BEFORE THIS POINT HAVE BEEN TESTED

*/

// Frees the entire list
void destroyList(Node * head) {
    while(head != NULL) {
        Node * ptr = head -> next;
        free(head);
        head = ptr;
    }
}

// Remove one value from the list
void removeNode(Node * head, int value) {
    
}


