#include "file_io.h"
#include "circularQueue/circular_queue.h"

int read_file(char *file_path)
{
    
    // creating file pointer for data
    FILE *data_file = fopen(file_path, "r");

    // considering if the test case fail
    if(data_file == NULL) return 1;

    char time_stamp[20];
    double temperature;

    CircularBuffer* circular_buffer = initalize_queue();

    fscanf(data_file, "%*[^\n]\n"); // skipping the header line

    while(fscanf(data_file, "%19[^,],%lf", time_stamp, &temperature) == 2)
    {

        
        
    }    

}