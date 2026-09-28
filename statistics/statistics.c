#include "statistics.h"
#include <string.h>

double get_median(CircularBuffer* Circular_buffer)
{
    double copy[SIZE];
    int n = Circular_buffer->buffer_size;
    memcpy(copy, Circular_buffer->buffer, sizeof(double) * n);

    if (n % 2 != 0) {
        return quickSelect(copy, 0, n - 1, n / 2);
    } else {
        double m1 = quickSelect(copy, 0, n - 1, n / 2 - 1);
        double m2 = quickSelect(copy, 0, n - 1, n / 2);
        return (m1 + m2) / 2.0;
    }
}


double get_mad(CircularBuffer* circular_buffer, double median)
{
    // median passed in from caller — no redundant recomputation

    int n = circular_buffer->buffer_size;
    double temp[SIZE];
    for(int i = 0; i < n; i++)
    {
        temp[i] = fabs(circular_buffer->buffer[i] - median);
    }

    if (n % 2 != 0) {
        return quickSelect(temp, 0, n - 1, n / 2);
    } else {
        double m1 = quickSelect(temp, 0, n - 1, n / 2 - 1);
        double m2 = quickSelect(temp, 0, n - 1, n / 2);
        return (m1 + m2) / 2.0;
    }
}


double get_zscore(double current_value, double median, double MAD)
{
    if (MAD == 0) return 0;
    return fabs(0.6745 * (current_value - median) / MAD);

}