#include "circular_buffer.h"
#include "file_io.h"
#include "statistics.h"

int main(void) {

  char file_path[256]; // creating a string to store the file path

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
  CircularBuffer *circular_buffer = initialize_queue();

  char time_stamp[20];
  double temperature;
  double median, MAD, z_score;
  int anomaly_count = 0;

  // opening output file once before the loop
  FILE *anomaly_file = fopen("anomalies.csv", "a");
  if (anomaly_file == NULL) {
    fprintf(stderr, "Error: Failed to open output file.\n");
    fclose(data_file);
    free(circular_buffer);
    return 1;
  }

  // reading file one row at a time and evaluating anomalies against the baseline
  while (read_file(data_file, time_stamp, &temperature)) {

    if (is_full(circular_buffer)) {

      median = get_median(circular_buffer);
      MAD = get_mad(circular_buffer, median); // median passed in — not recomputed
      z_score = get_zscore(temperature, median, MAD);

      if (z_score > THRESHOLD) {
        file_write(anomaly_file, temperature, time_stamp);
        anomaly_count++;
      }
    }

    enqueue(circular_buffer, &temperature);
  }

  free(circular_buffer);
  fclose(data_file);
  fclose(anomaly_file);

  printf("Done. %d anomalies detected. Results written to anomalies.csv\n", anomaly_count);
  return 0;
}
