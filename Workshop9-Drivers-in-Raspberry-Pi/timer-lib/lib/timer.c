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
    return 0.0;
}

double get_time()
{
    return 1.0;
}
