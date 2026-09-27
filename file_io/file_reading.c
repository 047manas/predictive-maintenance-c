#include "file_io.h"

int read_file(FILE *data_file, char *time_stamp, double *temperature)
{

    // reading one row from the file into the caller's buffers
    // returns 1 if a valid row was read, 0 on EOF or parse failure
    return fscanf(data_file, " %19[^,],%lf\n", time_stamp, temperature) == 2;

}