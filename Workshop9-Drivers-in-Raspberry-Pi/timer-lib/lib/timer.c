#include "../include/timer.h"


void read_file(char* str, int N)
{
    // Open file
    FILE* file = fopen(TIMER_DIR, "r");

    // Check if the file was opened
    if (file == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    // Read content
    fgets(str, N, file);

    // Close file
    fclose(file);
}

double generate_random_number(double high, double low)
{
    char* data = (char*) calloc(2, sizeof(char));
    read_file(data, 2);
    
    int number = *data;
    double rand_num = number % (int)(high - low) + low;
    
    free(data);

    return rand_num;
}

double get_time()
{
    return 1.0;
}
