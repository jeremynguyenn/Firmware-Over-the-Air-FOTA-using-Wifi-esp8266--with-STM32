#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "bsp.h"
#include "adc.h"
#include "circular_buffer.h"
#include "esp82xx_lib.h"

#define SSID_NAME  "TP-Link_9A4E"
#define PASSKEY    "94933581"

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


	esp8266_init(SSID_NAME,PASSKEY);


	while(1)
	{



	}
}

