#include "../include/gpio_manager.h"


/**
 * This function opens a pin to work with.
 * 
 * Params:
 *    int pin - pin number.
 */
void openPin(int pin)
{
   // Open and get the file descriptor
   int file_descriptor = open("/sys/class/gpio/export", O_WRONLY);

   if (file_descriptor == -1)
   {
      perror("Unable to open /sys/class/gpio/export.\n");
      exit(1);
   }

   // Store in buffer the pin value to work.
   char buffer[MAX_BUFFER_SIZE];
   ssize_t size = snprintf(buffer, MAX_BUFFER_SIZE, "%d", pin);

   // Writing the pin in the export file
   if (write(file_descriptor, buffer, size) == -1)
   {
      close(file_descriptor);
      perror("Error writing to /sys/class/gpio/export");
      exit(1);
   }

   close(file_descriptor);
}

/**
 * This function sets a pin into input or output mode.
 * 
 * Params
 *    int pin - pin to configure.
 *    int MODE - INPUT or OUTPUT constants. Error otherwise.
 */
void pinMode(int pin, int MODE)
{
   char gpio_file_path[DIRECTION_CHAR_SIZE];

   // Get the pin file path
   snprintf(gpio_file_path, DIRECTION_CHAR_SIZE,
            "/sys/class/gpio/gpio%d/direction", pin);

   // Open and get the file descriptor
   int file_descriptor = open(gpio_file_path, O_WRONLY);

   if (file_descriptor == -1)
   {
      fprintf(stderr, "Could not open the file %s.\n",
              "/sys/class/gpio/gpio%d/direction");
      exit(1);
   }

   // Input or output mode
   if (MODE == INPUT || MODE == OUTPUT)
   {
      if (write(file_descriptor, MODE ? "out" : "in", INPUT ? 3 : 2) == -1)
      {
         close(file_descriptor);
         fprintf(stderr, "The pin mode could not be written in the file %s.\n",
                 "/sys/class/gpio/gpio%d/direction");
         exit(1);
      }
   }
   // Invalid mode
   else
   {
      close(file_descriptor);
      perror("You wrote a wrong mode for this pin, check out if it is 0 for "
            "'input mode', or 1 for 'output mode'\n");
      exit(1);
   }

   close(file_descriptor);
}

/**
 * This function writes a digital value in a pin.
 * 
 * Params:
 *    - int pin - pin to write.
 *    - int value - LOW or HIGH constants.
 */
void digitalWrite(int pin, int value)
{
   char value_path[MAX_VALUE_LEN];

   // Get the pin file path
   snprintf(value_path, MAX_VALUE_LEN, "/sys/class/gpio/gpio%d/value", pin);

   // Open and get the file descriptor
   int file_descriptor = open(value_path, O_WRONLY);

   if (file_descriptor == -1)
   {
      fprintf(stderr, "Could not open %s.\n", value_path);
      exit(1);
   }

   // Change the pin value
   if(value == LOW || value == HIGH)
   {
      if(write(file_descriptor, value ? "1" : "0", 1) == -1)
      {
         fprintf(stderr, "Could not write %d on the pin %d\n", value, pin);
         exit(1);
      }
   }
   // Invalid value
   else
   {
      error("Invalid value: HIGH to turn on or LOW to turn off a pin\n");
      exit(1);
   }

   close(file_descriptor);
}

/**
 * This function reads the analog value in a pin.
 * 
 * Params:
 *    int pin - pin to read.
 */
int digitalRead(int pin)
{
   char value_path[MAX_VALUE_LEN];
   char value_str[MAX_BUFFER_SIZE];

   // Get the pin file path
   snprintf(value_path, MAX_VALUE_LEN, "/sys/class/gpio/gpio%d/value", pin);

   // Open and get the file descriptor
   int file_descriptor = open(value_path, O_RDONLY);

   if (file_descriptor == -1)
   {
      fprintf(stderr, "Could not open %s.\n", value_path);
      exit(1);
   }

   // Read value in the pin
   if (read(file_descriptor, value_str, MAX_BUFFER_SIZE) == -1)
   {
      fprintf(stderr, "Could not read the file.\n");
      exit(1);
   }

   close(file_descriptor);

   // Convert value to string
   int read_value = atoi(value_str);

   return read_value;
}

/**
 * This function blinks a LED.
 * 
 * Params:
 *    int pin - pin to blink.
 *    float freq - blink frequency.
 *    double duration - blink duration.
 */
void blink(int pin, float freq, double duration)
{
   // Validate frequency
   if (freq <= 0)
   {
      fprintf(stderr, "Ensure you put a value greater than 0.\n");
      exit(1);
   }

   // Compute the period
   float period = 1 / freq;

   // Current pin value
   int value = HIGH;
   float current_time = 0;

   // Repeat until time is up
   while (current_time < duration)
   {
      // Change the pin state
      digitalWrite(pin, value);
      // Wait a time
      sleep(period);

      // Change the state
      value = HIGH - value;
      current_time += period;
   }
}

/**
 * This function closes a pin.
 * 
 * Params:
 *    int pin - pin number.
 */
void closePin(int PIN)
{
   // Open and get the file descriptor
   int file_descriptor = open("/sys/class/gpio/unexport", O_WRONLY);

   if (file_descriptor == -1)
   {
      perror("Unable to open /sys/class/gpio/unexport.\n");
      exit(1);
   }

   // Store in buffer the pin value to work.
   char buffer[MAX_BUFFER_SIZE];
   ssize_t size = snprintf(buffer, MAX_BUFFER_SIZE, "%d", PIN);

   // Writing the pin in the unexport file
   if (write(file_descriptor, buffer, size) == -1)
   {
      close(file_descriptor);
      perror("Error writing to /sys/class/gpio/unexport");
      exit(1);
   }

   close(file_descriptor);
}

