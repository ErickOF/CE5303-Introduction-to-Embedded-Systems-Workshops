#include "../include/gpio_manager.h"
#include <stdio.h>

#define INPUT_PIN 4
#define OUTPUT_PIN1 17
#define OUTPUT_PIN2 8


int main(int argc, char const* argv[])
{
    // Put a pin in HIGH
    openPin(OUTPUT_PIN1);
    pinMode(OUTPUT_PIN1, OUTPUT);
    digitalWrite(OUTPUT_PIN1, HIGH);

    // Blink a LED
    openPin(OUTPUT_PIN2);
    pinMode(OUTPUT_PIN2, OUTPUT);
    blink(OUTPUT_PIN1, 1, 5);

    // Pin to read
    openPin(INPUT_PIN);
    pinMode(INPUT_PIN, INPUT);
    // Read pin
    printf("Reading %d from %d\n", digitalRead(INPUT_PIN), INPUT_PIN);
    sleep(1);

    // Free pin
    closePin(OUTPUT_PIN1);
    closePin(OUTPUT_PIN2);
    closePin(INPUT_PIN);

    return 0;
}