#include "circular_queue.h"
#include "file_io.h"

int main(void) {

  char file_path[50]; // creating a string to store the file path

  // taking file path from the user
  printf("Enter the file path: ");
  // taking input from user and making sure that input is valid
  if (fgets(file_path, sizeof(file_path), stdin) == NULL) {

    fprintf(stderr, "Error: Failed to read input.\n");
    return 1;
  }

  // the input contains \n at end as user press enter after typing the path
  // removing it
  file_path[strcspn(file_path, "\n")] = '\0';

  // opening the file
  FILE *data_file = fopen(file_path, "r");
  if (data_file == NULL) {

    fprintf(stderr, "Error: Failed to open file.\n");
    return 1;
  }

  fscanf(data_file, "%*[^\n]\n"); // skipping the header line

  // initializing the circular buffer
  CircularBuffer *circular_buffer = initalize_queue();

  char time_stamp[20];
  double temperature;

  double median, MAD;

  // reading file one row at a time and storing temperature in the queue
  while (read_file(data_file, time_stamp, &temperature)) {

    enqueue(circular_buffer, &temperature);

    if (is_full(circular_buffer)) {
      // buffer holds a full day of readings - anomaly detection goes here



    }
  }

  free(circular_buffer);
  fclose(data_file);

  return 0;
}
