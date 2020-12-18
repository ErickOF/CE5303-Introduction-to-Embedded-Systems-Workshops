
#include <sys/mman.h> //mmap
#include <err.h> //error handling
#include <fcntl.h> //file ops
#include <unistd.h> //usleep
#include <stdio.h>

//Static base
static unsigned GPIO_BASE = 0x3f200000;
static unsigned UART_BASE = 0x3f201000;
static unsigned FUARTCLK  = 48000000; //47923200;

//Registers pointers
volatile unsigned int * gpiobase;
volatile unsigned int * gpfsel1;

volatile unsigned int * uartbase;
volatile unsigned int * uartdr;
volatile unsigned int * uartctrl;
volatile unsigned int * uartlcrh;
volatile unsigned int * uartlintbr;
volatile unsigned int * uartlfbr;
volatile unsigned int * uartris;




void initPtrs(){
	int fd = -1;
	//Loading /dev/mem into a file
	if ((fd = open("/dev/mem", O_RDWR, 0)) == -1)
            err(1, "Error opening /dev/mem");

   //Mapping GPIO base physical address 
	gpiobase = (unsigned int*)mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);

	//Mapping UART base physical address 
	uartbase = (unsigned int*)mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, UART_BASE);

	//Check for mapping errors
	if (gpiobase == MAP_FAILED | uartbase == MAP_FAILED) 
		errx(1, "Error during mapping devices");

	//Assigning proper pointers
	gpfsel1  	= gpiobase + 0x1;
	uartdr   	= uartbase; 
	uartctrl 	= uartbase + 0xC;
	uartlcrh 	= uartbase + 0xB;
	uartlintbr 	= uartbase + 0x9;
	uartlfbr   	= uartbase + 0xA;
	uartris    	= uartbase + 0xF;
}


void gpioConfig(){
     // 10 0100 0000 0000 0000
	*gpfsel1 = *gpfsel1 | 0x24000;
}

void uartConfig(int BaudRate){
	//disable FIFO
	*uartlcrh = *uartlcrh & 0xffffff6f;
	//set baudrate dividers
	*uartlintbr = (unsigned int) (FUARTCLK / (16 * BaudRate));
	*uartlfbr =   (unsigned int) ((FUARTCLK % (16 * BaudRate)) * 64 /(16 * BaudRate));
}

void uartSend(char data){
	*uartdr = data;
}

//void uartReceive(){
//bit 6 100 0000
//	while(!(*uartris&0x40))
//}

int main(int argc, char const *argv[])
{
	initPtrs();
	gpioConfig();
	uartConfig(9600);
	printf("gpfsel1 = 0x%08x\n", * gpfsel1);
	printf("uartctrl = 0x%08x\n", * uartctrl);
	printf("uartlcrh = 0x%08x\n", * uartlcrh);
	printf("uartlintbr = 0x%08x\n", * uartlintbr);
	printf("uartlfbr = 0x%08x\n", * uartlfbr);
	int i = 0;
	while(1){
	uartSend(i);
	i++;
	usleep(10000);
	}

	return 0;
}