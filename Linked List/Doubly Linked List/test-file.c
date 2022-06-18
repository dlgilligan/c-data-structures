#include "doubly-linked-list-funcs.h"

int main() {
    List l;
    l.start = NULL;
    display_list(l); // Empty List
    insert_begin(&l, 100); // start -> 100
    insert_begin(&l, 200); // start -> 200 -> 100
    display_list(l); //  200 100
    reverse_iteration(l);// 100 200
    
   
    
    insert_end(&l, 400); // start -> 200->100->400
    insert_end(&l, 500); // start -> 200 -> 100->400->500
    display_list(l); //  200 100 400 500
    
    reverse_iteration(l); // 500 400 100 200 
    
    printf("\n Deleted Element from First = %d ",delete_begin(&l));// 200
    display_list(l); //  400 100 200
    
    printf("\n Deleted Element from First = %d ",delete_begin(&l));// 400
    display_list(l); //  100 200
    
    printf("\n Deleted Element from last = %d ",delete_end(&l));// 400
    display_list(l); 
    
}