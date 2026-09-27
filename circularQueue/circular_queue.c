#include "circular_queue.h"

CircularBuffer* initialize_queue(void)
{

    CircularBuffer* circular_buffer = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    circular_buffer->head = -1;
    circular_buffer->buffer_size = 0;
    return circular_buffer;

}

void enqueue(CircularBuffer *circular_buffer ,double* data)
{

    if(circular_buffer->head == -1)
    {

        circular_buffer->head = 0;

    }

    else
    {

        circular_buffer->head = (circular_buffer->head + 1) % SIZE;

    }
    
    circular_buffer->buffer[circular_buffer->head] = *data;
    if(circular_buffer->buffer_size < SIZE)
        circular_buffer->buffer_size++;

}

int is_full(CircularBuffer *circular_buffer)
{

    return circular_buffer->buffer_size == SIZE;

}