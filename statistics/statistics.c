#include "statistics.h"

double get_median(CircularBuffer* Circular_buffer)
{

    return quick_select(Circular_buffer, Circular_buffer->buffer_size / 2);

}

double get_mad(CircularBuffer* circular_buffer)
{

    CircularBuffer* temp = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    
    double median = get_median(circular_buffer);
    
    for(int i = 0; i < 288; i++)
    {

        temp->buffer[i] = fabs(circular_buffer->buffer[i] - median);

    }

    temp->head = temp->buffer_size = 288;

    double mad = get_median(temp);

    free(temp);
    temp = NULL;

    return mad;

}