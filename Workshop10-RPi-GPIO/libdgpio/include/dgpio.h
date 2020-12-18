#ifndef _D_GPIO_LIB_H
#define _D_GPIO_LIB_H


#include <sys/mman.h> // mmap
#include <err.h> // error handling
#include <fcntl.h> // file ops
#include <unistd.h> // usleep

// Static base
static unsigned GPIO_BASE = 0x3f200000;

// Regs pointers
volatile unsigned int* gpfsel0;
volatile unsigned int* gpset0;
volatile unsigned int* gpclr0;
volatile unsigned int* gplev0;

/* Function prototypes */
/**
 * This function initializes the pointers. It performs memory mapping,
 * exits if mapping fails.
 */
void gpioInitPtrs();

/**
 * This function sets GPIO2 as output.
 *
 * Params:
 *      int pin - number of the pin to set.
 *      unsigned char function - function to set to the pin.
 *          000 -> Input.
 *          001 -> Output.
 *          010 -> Function 5
 *          011 -> Function 4
 *          100 -> Function 0
 *          101 -> Function 1
 *          110 -> Function 2
 *          111 -> Function 3
 */
void gpioSetMode(int pin, unsigned char function);

/**
 * This function writes to GPIO2.
 *
 * Params:
 *      int pin - number of the pin to write.
 *      unsigned char bit - 1 for a HIGH, value 0 for LOW value.
 */
void gpioWrite(int pin, unsigned char bit);

/**
 * This function reads to GPIO2.
 *
 * Params:
 *      int pin - number of the pin to read.
 */
int gpioRead(int pin);


#endif /* _D_GPIO_LIB_H */
