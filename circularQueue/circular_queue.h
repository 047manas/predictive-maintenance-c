#include<stdio.h>
#include<stdlib.h>
#define SIZE 288

typedef struct CircularBuffer
{
    double buffer[288];
    int head;
    int buffer_size;
} CircularBuffer;

CircularBuffer* initalize_queue(void); // create the buffer data type 
void enqueue(CircularBuffer *circular_buffer, double* data); // adding element to the buffer
int is_full(CircularBuffer *circular_buffer); // returns 1 if buffer is at capacity