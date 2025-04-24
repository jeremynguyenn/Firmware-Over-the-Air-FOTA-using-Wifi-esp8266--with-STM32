#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"
#include "adc.h"
#include "circular_buffer.h"

/*Modules:
 * FPU
 * UART
 * TIMEBASE
 * GPIO (BSP)
 * ADC
 * */



#define  GPIOAEN		(1U<<0)
#define  PIN5			(1U<<5)
#define  LED_PIN		PIN5

bool btn_state;
uint32_t sensor_value;
int main()
{
	/*Enable FPU*/
	fpu_enable();

	/*Initialize debug UART*/
	debug_uart_init();
	esp_uart_init();

	/*Initialize timebase*/
	timebase_init();

	/*Initialize LED*/
	led_init();

	/*Initialize Push button*/
	button_init();

	/*Initialize ADC*/
	pa1_adc_init();


	circular_buffer_init();
	/*Start conversion*/
	//start_conversion();

	while(1)
	{

		//printf("Slave Dev UART...\n\r");

		buffer_send_string("Hello DEBUG\n\r",DEBUG_PORT );
		buffer_send_string("Hello SLAVE DEV\n\r",SLAVE_DEV_PORT );

		delay(1);

	}
}

