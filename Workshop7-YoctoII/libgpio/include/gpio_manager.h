#ifndef LIBGPIO_GPIO_MANAGER_H
#define LIBGPIO_GPIO_MANAGER_H


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1
#define MAX_BUFFER_SIZE 3
#define DIRECTION_CHAR_SIZE 35
#define MAX_VALUE_LEN 30


void openPin(int pin);
void pinMode(int pin, int MODE);
void digitalWrite(int pin, int value);
int digitalRead(int pin);
void blink(int pin, float freq, double duration);
void closePin(int PIN);


#endif /* LIBGPIO_GPIO_MANAGER_H */
