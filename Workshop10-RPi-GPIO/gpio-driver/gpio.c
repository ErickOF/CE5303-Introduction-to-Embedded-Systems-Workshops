
#include <sys/mman.h> // mmap
#include <err.h> // error handling
#include <fcntl.h> // file ops
#include <unistd.h> // usleep



//Static base
static unsigned GPIO_BASE = 0x3f200000;

//Registers pointers
volatile unsigned int* gpfsel0;
volatile unsigned int* gpset0;
volatile unsigned int* gpclr0;

/*function prototypes*/
void gpioInitPtrs();
void gpioSetMode();
void gpioWrite(unsigned char bit);



// Initialize pointers: performs memory mapping, exits if mapping fails
void gpioInitPtrs(){
	int fd = -1;
	//Loading /dev/mem into a file
	if ((fd = open("/dev/mem", O_RDWR, 0)) == -1)
            err(1, "Error opening /dev/mem");

    //Mapping GPIO base physical address 
	gpfsel0 = (unsigned int*)mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);

	//Check for mapping errors
	if (gpfsel0 == MAP_FAILED)
		errx(1, "Error during mapping GPIO");
	
	//Set registers pointers
	gpset0 = gpfsel0 + 0x7; // offset 0x1C / 4 = 0x7
	gpclr0 = gpfsel0 + 0xA; // offset 0x28 / 4 = 0xA
}
//Sets GPIO2 as output 
void gpioSetMode(){   
	*gpfsel0 = *gpfsel0 | 0x40; //0 0100 0000
}

//Writes to GPIO2
void gpioWrite(unsigned char bit){
	if (bit) *gpset0 = 0x4; //sets bit
	else *gpclr0 = 0x4; //clears bit
}

int main(int argc, char const *argv[])
{
	gpioInitPtrs();
	gpioSetMode();

	//toggle GPIO2
	gpioWrite(1);
	usleep(1000000);
	gpioWrite(0);
	
	return 0;
}
