#include "file_io/file_io.h"

int main(void)
{

    char file_path[50]; // creating a string to store the file path
    
    // taking file path from the user
    printf("Enter the file path: ");
    // taking input from user and making sure that input is valid
    if(fgets(file_path, sizeof(file_path), stdin) == NULL)
    {

        fprintf(stderr, "Error: Failed to read input.\n");
        return 1;
    
    }

    // the input contains \n at end as user press enter after typing the path
    // removing it
    
    file_path[strcspn(file_path, "\n")] = '\0';

    // reading data in file path
    if(read_file(file_path) == 1) fprintf(stderr, "Error: Failed to open file");

    return 0;
    
}