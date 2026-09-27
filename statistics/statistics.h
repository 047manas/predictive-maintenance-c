#include<stdlib.h>
#include "circular_queue.h"
#include "quick_select.h"
#include<math.h>

#define THRESHOLD 3.5

double get_median(CircularBuffer* Circular_buffer);
double get_mad(CircularBuffer* circular_buffer, double median);
double get_zscore(double current_value, double median, double MAD);