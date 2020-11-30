#include <stdio.h>
#include <stdlib.h>


#include "../include/timer.h"


int main()
{
    double start_time = get_time();

    for (int i = 1; i < 10000; i++)
    {
        // Test random number generator
        printf("Random number: %f\n", generate_random_number(2 * i, 0));
    }

    // Test time
    printf("\nExecution time: %fs\n", get_time() - start_time);

    return 0;
}
