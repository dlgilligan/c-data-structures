#include "singly-linked-list-funcs.h"

int main () {

    Node * head = createList(5);
    printf("Initial List: ");
    printList(head);
    printf("\n");

    addNodeEnd(head,6);
    printf("List after adding 6 to the end: ");
    printList(head);
    printf("\n");

    head = addNodeFront(head,0);
    printf("List after adding 0 to the front: ");
    printList(head);

}