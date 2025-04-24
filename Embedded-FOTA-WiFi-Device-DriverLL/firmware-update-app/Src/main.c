#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"

/*Modules:
 * FPU
 * UART
 * GPIO
 * TIMEBASE
 * */



#define  GPIOAEN		(1U<<0)
#define  PIN5			(1U<<5)
#define  LED_PIN		PIN5


#define VECT_TAB_BASE_ADDRESS			FLASH_BASE   //0x08000000
#define VECT_TAB_OFFSET					0x8000
int main()
{
	/*Enable FPU*/
	fpu_enable();

	/*Initialize debug UART*/
	debug_uart_init();

	while(1)
	{

		printf("Main Application Update:  EmbeddedExpertIO-------\n\r");

		for(int i = 0; i < 9000; i++){}
	}
}

void SystemInit(void)
{
	SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET;
}
