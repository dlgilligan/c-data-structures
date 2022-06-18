#include "queue-funcs.h"

int main () {
    struct Queue * queue = createQueue(10);

    enqueue(queue,10);
    int frontVal = front(queue);
    int rearVal = rear(queue);
    printf("Front is %d\n",frontVal);
    printf("Rear is %d\n",rearVal);
    printf("\n");

    enqueue(queue,20);
    frontVal = front(queue);
    rearVal = rear(queue);
    printf("Front is %d\n",frontVal);
    printf("Rear is %d\n",rearVal);
    printf("\n");

    enqueue(queue,30);
    frontVal = front(queue);
    rearVal = rear(queue);
    printf("Front is %d\n",frontVal);
    printf("Rear is %d\n",rearVal);
    printf("\n");

    
}