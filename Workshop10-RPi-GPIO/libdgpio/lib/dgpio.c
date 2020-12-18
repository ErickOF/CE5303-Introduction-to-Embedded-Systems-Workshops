#include "../include/dgpio.h"


/**
 * This function initializes the pointers. It performs memory mapping,
 * exits if mapping fails.
 */
void gpioInitPtrs()
{
    int fd = -1;

    // Loading /dev/mem into a file
    if ((fd = open("/dev/mem", O_RDWR, 0)) == -1)
    {
        err(1, "Error opening /dev/mem");
    }

    // Mapping GPIO base physical address
    gpfsel0 = (unsigned int*) mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED,
                                   fd, GPIO_BASE);

    // Check for mapping errors
    if (gpfsel0 == MAP_FAILED)
    {
        errx(1, "Error during mapping GPIO");
    }

    // Set registers pointers
    gpset0 = gpfsel0 + 0x7;
    gpclr0 = gpfsel0 + 0xA;
    gplev0 = gpfsel0 + 0xD;
}

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
void gpioSetMode(int pin, unsigned char function)
{
    *gpfsel0 = *gpfsel0 & ~((0b111 & ~function) << 3*pin);
    *gpfsel0 = *gpfsel0 | ((0b111 & function) << 3*pin);
}

/**
 * This function writes to GPIO2.
 *
 * Params:
 *      int pin - number of the pin to write.
 *      unsigned char bit - 1 for a HIGH, value 0 for LOW value.
 */
void gpioWrite(int pin, unsigned char bit)
{
    if (bit)
    {
        // Sets bit
        *gpset0 = 1 << pin;
    }
    else
    {
        // Clears bit
        *gpclr0 = 1 << pin;
    }
}

/**
 * This function reads to GPIO2.
 *
 * Params:
 *      int pin - number of the pin to read.
 */
int gpioRead(int pin)
{
    return (*gplev0 >> (pin % 32)) & 0x00000001;
}

