
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
volatile unsigned int * uarticr;
volatile unsigned int * uartmis;
volatile unsigned int * uartimsc;
volatile unsigned int * uartfr;
volatile unsigned int * uartitop;




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
	uarticr   	= uartbase + 0x11;
	uartmis   	= uartbase + 0x10;
	uartimsc   	= uartbase + 0xE;
	uartfr = uartbase + 0x6;
	uartitop = uartbase + 0x22;
}


void gpioConfig(){
     // 10 0100 0000 0000 0000
	*gpfsel1 = *gpfsel1 | 0x24000;
}

void uartConfig(int BaudRate){
	//disable uart
	*uartctrl = *uartctrl & 0xFFFFFFF0;
	//enable RX and TX
	*uartctrl = *uartctrl | 0x300;
	//clear interrupts
	*uarticr = *uarticr | 0xFF;
	//loopback - for testing only - disabled
	//*uartctrl = *uartctrl | 0x80;
	//disable FIFO
	*uartlcrh = *uartlcrh & 0xffffff6f;
	//set baudrate dividers
	*uartlintbr = (unsigned int) (FUARTCLK / (16 * BaudRate));
	*uartlfbr =   (unsigned int) ((FUARTCLK % (16 * BaudRate)) * 64 /(16 * BaudRate));
	//enable interrupt mask
	*uartimsc = *uartimsc | 0x50;
	//enable uart again
	*uartctrl = *uartctrl | 0x1;
}

void uartSend(char data){
	*uartdr = data;
}

int uartReceive(){

	//while(!(*uartris&0x40));

	while(*uartris != 0x20);
	//printf("IMSC = 0x%08x\n",*uartimsc);
	//printf("MIS = 0x%08x\n",*uartmis);
	
	*uarticr = *uarticr|0x20;
	return *uartdr;
}

int main(int argc, char const *argv[])
{
	initPtrs();
	gpioConfig();
	uartConfig(1154000);
	*uartitop = *uartitop | 0x400;
	//*uarticr = *uarticr|0xFF;
	
	printf("Interrupt mask states = 0x%08x\n", *uartimsc);
	printf("Control register = 0x%08x\n", *uartctrl);
	int i = 0;
	
	while(1){
		printf("ITOP= 0x%08x\n",*uartitop);
		usleep(100000);
		uartSend(i);
		printf("*************************************************************\n");
		printf("Interrupt Flag Register prior to reception = 0x%08x\n",*uartris);

		//printf("Flag Register = 0x%08x\n",*uartfr);
		printf("Data = 0x%08x\n",uartReceive());
		printf("Interrupt Flag Register after reception= 0x%08x\n",*uartris);

		printf("\n\n");

	
		i++;
	}

	return 0;
}
