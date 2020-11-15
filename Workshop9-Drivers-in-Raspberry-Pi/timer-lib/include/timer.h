#ifndef _TIMER_LIB_TIMER_H_
#define _TIMER_LIB_TIMER_H_

#include <stdlib.h>
#include <stdio.h>


const static char* TIMER_DIR = "/dev/memory";


/**
 * This function reads a file.
 *
 * Params:
 *      char* str - char pointer to store the read content.
 *      int n - number of chars to read.
 * 
 */
void read_file(char* str, int N);
double generate_random_number(double high, double low);
double get_time();


#endif /* _TIMER_LIB_TIMER_H_ */
