
#ifndef __CIRCULARBUFFER_H__
#define __CIRCULARBUFFER_H__

typedef void (* circularbuffer_destroybuffer)(void *);

typedef struct Item {
    void * data;
} Item;

typedef struct CircularBuffer {
    size_t size;
    size_t start;
    size_t end;
    Item * buffer;
} CircularBuffer;

CircularBuffer * circularbuffer_init(size_t, void *);

int circularbuffer_add(CircularBuffer *, void *);

void * circularbuffer_read(CircularBuffer *);

int circularbuffer_destroy(CircularBuffer *, circularbuffer_destroybuffer);

#endif