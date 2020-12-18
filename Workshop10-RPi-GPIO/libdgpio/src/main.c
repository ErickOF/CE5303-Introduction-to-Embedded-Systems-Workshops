#include "../include/dgpio.h"

#define INPUT 0b000
#define OUTPUT 0b001


int main(int argc, char const *argv[])
{
    int OUTPUT_PIN = 2;
    int INPUT_PIN = 3;

    gpioInitPtrs();
    gpioSetMode(OUTPUT_PIN, OUTPUT);
    gpioSetMode(INPUT_PIN, INPUT);

    while (1)
    {
        gpioWrite(OUTPUT_PIN, 1);
        usleep(1000000000);

        printf("r %d\n", gpioRead(OUTPUT_PIN));

        gpioWrite(OUTPUT_PIN, 0);
        usleep(1000000);

        printf("r %d\n", gpioRead(OUTPUT_PIN));

        printf("r %d\n\n", gpioRead(INPUT_PIN));
    }

    return 0;
}