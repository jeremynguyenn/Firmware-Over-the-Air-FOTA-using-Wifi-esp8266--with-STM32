#include "esp82xx_lib.h"

#define esp82xx_port		SLAVE_DEV_PORT
#define debug_port			DEBUG_PORT



static void esp82xx_reset(void);
static void esp82xx_startup_test(void);
static void esp82xx_sta_mode(void);
static void esp82xx_ap_connect(char *ssid, char *password);

void esp8266_init(char *ssid, char *password)
{
	circular_buffer_init();
	esp82xx_reset();
	esp82xx_startup_test();
	esp82xx_sta_mode();
	esp82xx_ap_connect(ssid, password);
}
 static void esp82xx_startup_test(void)
{
	/*Clear ESP uart buffer*/
	buffer_clear(esp82xx_port);

	/*Send test command*/
	buffer_send_string("AT\r\n",esp82xx_port);

	/*Wait for "OK" response*/
	while(!(is_response("OK\r\n"))){}


	buffer_send_string("AT startup test successful....\n\r",debug_port);
}


static void esp82xx_reset(void)
{
	/*Clear ESP uart buffer*/
	buffer_clear(esp82xx_port);

	/*Send test command*/
	buffer_send_string("AT+RST\r\n",esp82xx_port);

	/*Delay for 1 second*/
	systick_delay_ms(1000);

	/*Wait for "OK" response*/
	while(!(is_response("OK\r\n"))){}

	buffer_send_string("Reset was successful....\n\r",debug_port);
}


static void esp82xx_sta_mode(void)
{
	/*Clear ESP uart buffer*/
	buffer_clear(esp82xx_port);

	/*Send test command*/
	buffer_send_string("AT+CWMODE=1\r\n",esp82xx_port);

	/*Wait for "OK" response*/
	while(!(is_response("OK\r\n"))){}


	buffer_send_string("STA Mode set successful....\n\r",debug_port);
}


static void esp82xx_ap_connect(char *ssid, char *password)
{
	char data[80];

	/*Clear ESP uart buffer*/
	buffer_clear(esp82xx_port);

	buffer_send_string("Connecting to access point....\n\r",debug_port);

	/*Pust ssid, password and command into one string packet*/
	sprintf(data,"AT+CWJAP=\"%s\",\"%s\"\r\n",ssid,password);

	/*Send test command*/
	buffer_send_string(data,esp82xx_port);

	/*Wait for "OK" response*/
	while(!(is_response("OK\r\n"))){}

    sprintf(data,"Connected : \"%s\"\r\n",ssid);

	buffer_send_string(data,debug_port);
}
