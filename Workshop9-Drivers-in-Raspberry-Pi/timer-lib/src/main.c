#include <stdio.h>
#include <stdlib.h>


#include "../include/timer.h"


int main()
{
    // Number of chars to read + 1 (Due '\0' at the end of the file)
    int n = 5;
    // Ask for memory
    char* str = (char*) calloc(n, sizeof(char));

    // Test random number generator
    printf("Random number: %f\n", generate_random_number(10, 0));

    // Test time
    printf("Time: %f\n", get_time());

    // Test read_file
    read_file(str, n);
    printf("File: %s\n", str);

    // Free memory
    free(str);

    return 0;
}
