#include "statistics.h"
#include <string.h>

double get_median(CircularBuffer* Circular_buffer)
{
    double copy[SIZE];
    memcpy(copy, Circular_buffer->buffer, sizeof(double) * Circular_buffer->buffer_size);

    return quickSelect(copy, 0, Circular_buffer->buffer_size - 1, Circular_buffer->buffer_size / 2);

}


double get_mad(CircularBuffer* circular_buffer, double median)
{
    // median passed in from caller — no redundant recomputation

    double temp[SIZE];
    for(int i = 0; i < circular_buffer->buffer_size; i++)
    {
        temp[i] = fabs(circular_buffer->buffer[i] - median);
    }

    return quickSelect(temp, 0, circular_buffer->buffer_size - 1, circular_buffer->buffer_size / 2);

}


double get_zscore(double current_value, double median, double MAD)
{
    if (MAD == 0) return 0;
    return fabs(0.6745 * (current_value - median) / MAD);

}