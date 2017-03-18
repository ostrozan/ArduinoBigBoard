// Board.h

#ifndef _BOARD_h
#define _BOARD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GPIO.h"

//def modules
#define CAN_MODULE
//#define WIFI_MODULE
#define RTC_MODULE
#define GSM_MODULE
//#define RS485_MODULE

#ifdef CAN_MODULE
#include <mcp_can_dfs.h>
#include <mcp_can.h>
#endif // CAN_MODULE

#ifdef WIFI_MODULE
#include <ESP8266wifi.h>
#endif // WIFI_MODULE

#ifdef RTC_MODULE
#include <Wire.h>
#include <ds3231.h>
#include "DateTime.h"
#endif // RTC_MODULE

#ifdef GSM_MODULE
#include "GsmModule.h"
#endif // GSM_MODULE

#ifdef RS485_MODULE
#define PIN_CTRL485 22
#define SEND_485 digitalWrite(PIN_CTRL485, LOW);
#define REC_485 digitalWrite(PIN_CTRL485, HIGH);
#endif // RS485_MODULE


#define RELE_1 30
#define RELE_2 31
#define RELE_3 32
#define RELE_4 33
#define RELE_5 34
#define RELE_6 35
#define RELE_7 36
#define RELE_8 37

#define OPTO_IN_1 42
#define OPTO_IN_2 43
#define OPTO_IN_3 44
#define OPTO_IN_4 45
#define OPTO_IN_5 46
#define OPTO_IN_6 47
#define OPTO_IN_7 48
#define OPTO_IN_8 49



#define BTserial Serial
#define GSMserial Serial1
#define RS485serial Serial2
#define WIFIserial Serial3
	enum Modules
	{
    BT,GSM,RS485,WIFI
	};


class Board
{
public:

	Gpio_struct outputs[8];
	Gpio_struct inputs[8];
	Gpio_struct gpios[16];


	Board();
	~Board();

	void Init();   
    void BTinit(long baudRate);
    void GSMinit(long baudRate);
	void RS485init(long baudRate);
	void WIFIinit(long baudRate);	
	void CANInit(int speed);
	void Send(Modules modul, String str);
	void Send(Modules modul,char* arr);
    void I_O_init();
	void GpioInit(Gpio_struct *gpio, char pin, char type);

private:
    
};


#endif

