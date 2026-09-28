#include<stdio.h>
#include<stdlib.h>
#define SIZE 72

typedef struct CircularBuffer
{
    double buffer[72];
    int head;
    int buffer_size;
} CircularBuffer;

CircularBuffer* initialize_queue(void); // create the buffer data type 
void enqueue(CircularBuffer *circular_buffer, double* data); // adding element to the buffer
int is_full(CircularBuffer *circular_buffer); // returns 1 if buffer is at capacity