#include<stdio.h>
#include<stdlib.h> // for malloc 

typedef struct node {
    int info; //the information part of a Node 
    struct node* next; // points to the next Node
    struct node* prev; // points to the previous Node
} Node;


struct List {
    Node *start ; // pointer to the first Node of the list
}typedef List;


int insert_begin( List* list, int item) {
    Node * newNode =(Node*)malloc(sizeof(Node));// allocate memory for newnode
    if( newNode == NULL)
        return 1; // failure to insert node because of insufficient memory
     
    newNode->info = item ; // add data in the newNode
    if( list->start == NULL) {// if the list is Empty
        newNode->next = NULL;
        newNode->prev = NULL;
        list->start = newNode;
        return 0;
    }  else {
        // Atleast one node in list
        newNode->next = list->start;
        newNode->prev = NULL;
        list->start->prev = newNode;
        list->start = newNode;// newNode is now the first node, update start 
        return 0;// successful insertion of node 
    }
}


int insert_end( List* list, int item) {
    Node * newNode =(Node*)malloc(sizeof(Node));// allocate memory for newnode
    if( newNode == NULL)
         return 1; // failure to insert node because of insufficient memory
     
    newNode->info = item ; // add data in the newNode
    if( list->start == NULL) {// if list is empty 
        // new Node will be the first Node of list
        newNode->next = NULL;
        newNode->prev = NULL;
        list->start = newNode;
        return 0; 
    } else { // more than one node in list
        Node * temp= list->start;
        while( temp->next != NULL)// iterate
            temp = temp->next;
            
      temp->next = newNode;
      newNode->prev=temp;
      newNode->next= NULL;
      return 0;
    }
}


int delete_begin( List *list) {// list is passed by reference 
    if(list->start == NULL)// list is empty
        return -1;
    if( list->start->next == NULL) {// only one node in list
        int front_element = list->start->info;// store the info of 1st node
        Node *save = list->start;// save the address of the first node
        list->start = list->start->next;// update start 
        free(save);// release the memory of the node to be deleted 
        return front_element;// return the first element 
    }
     // more than one node in list
    int front_element = list->start->info;// store the info of 1st node
    Node *save = list->start;// save the address of the first node
    list->start->next->prev = NULL; // 2nd Node will now become the 1st NULL
    list->start = list->start->next;// update start 
    free(save);// release the memory of the node to be deleted 
    return front_element;// return the first element 
}


int delete_end( List *list) {// list is passed by reference 
    if(list->start == NULL)// list is empty
        return -1;
    if( list->start->next == NULL) {// only one node in list
        int front_element = list->start->info;// store the info of 1st node
        Node *save = list->start;// save the address of the first node
        list->start = list->start->next;// update start 
        free(save);// release the memory of the node to be deleted 
        return front_element;// return the first element 
    }
    // more than one node in list
    Node* temp;
    temp=list->start;
    while(list->start->next->next!=NULL) {
        temp=temp->next;
    }
    int front_element = temp->next->info;// store the info of last node
    Node *save = temp->next;// save the address of the last
    temp->next = NULL;
    temp->prev = temp; 
    free(save);
    return front_element;
}


int display_list(List list) {
    if(list.start == NULL) { // No nodes in the list
        printf("\nEmpty List\n");
        return -1;
    }
    printf("\n List is : ");
    Node *temp = list.start;// initialize an iterator with start
    while( temp != NULL ) { // iterate over all the nodes of the list
        printf("%5d", temp->info); // print the info part of the current node
        temp = temp->next;
    }
    return 0;
    
}
   
   
void reverse_iteration( List list) {
    printf("\n Reversed List is ");
    if( list.start == NULL) {
        printf("\nEmpty List ");
        return ;
    }
        
    Node *temp = list.start;
    while(temp->next != NULL) 
        temp=temp->next;
         
    while( temp != NULL) {
        printf(" %d ", temp->info);
        temp = temp->prev;
    }
        
}
