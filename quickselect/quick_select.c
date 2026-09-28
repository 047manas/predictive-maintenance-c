#include "quick_select.h"

double quickSelect(double *arr, int left, int right, int k) {

  if (left == right)
    return arr[left];

  int pivot_index = partition(arr, left, right);

  if (pivot_index == k)
    return arr[pivot_index];

  else if (pivot_index > k)
    return quickSelect(arr, left, pivot_index - 1, k);

  else
    return quickSelect(arr, pivot_index + 1, right, k);
}

int partition(double *arr, int left, int right) {

  int pivot_index = right;
  int start = left;
  int end = right - 1;

  while (start < end && start < right && end >= 0) {

    while (start < right && arr[pivot_index] > arr[start])
      start++;

    while (end >= 0 && arr[pivot_index] <= arr[end])
      end--;

    if (start < end && start < right && end >= 0) {

      double temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
    }
  }

  double temp = arr[pivot_index];
  arr[pivot_index] = arr[start];
  arr[start] = temp;

  return start;
}
