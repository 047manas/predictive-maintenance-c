#include<stdio.h>
#include<string.h>

int read_file(FILE *data_file, char *time_stamp, double *temperature);
int file_write(FILE *output_file, double temperature, char *time_stamp);