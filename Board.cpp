// 
// 
#define CAN_MODULE
//#define WIFI_MODULE

#include "Board.h"


Board::Board()
{
}

Board::~Board()
{
}
void Board:: Init()
{
	I_O_init();

}

void Board::BTinit(long baudRate)
{
	BTserial.begin(baudRate);
}

void Board::GSMinit(long baudRate)
{
	GSMserial.begin(baudRate);
}

void Board::RS485init(long baudRate)
{
	RS485serial.begin(baudRate);
}

#ifdef WIFI_MODULE
void Board::WIFIinit(long baudRate)
{
	WIFIserial.begin(baudRate);
}
#endif



#ifdef CAN_MODULE

void Board::CANInit(int speed)
{
	MCP_CAN CAN(53);
	CAN.begin(speed);
	pinMode(2, INPUT);
}
#endif

void Board::Send(Modules modul, String str)
{
	Serial.println("send");
	switch (modul)
	{
	case BT: Serial.println(str);
		break;
#ifdef GSM_MODULE
	case GSM: GSMserial.print(str);
		break;
#endif // GSM_MODULE
#ifdef RS485_MODULE
	case RS485: SEND_485 Serial2.print(str); delay(15); REC_485
		break;
#endif // RS485_MODULE
#ifdef WIFI_MODULE
	case WIFI:Serial3.print(str);
		break;
#endif //WIFI_MODULE
	default:
		break;
	}
}

void Board::Send(Modules modul, char * arr)
{
}



void Board::I_O_init()
{
	//inputs
	GpioInit(&inputs[0], OPTO_IN_1, INPUT_PULLUP);
	GpioInit(&inputs[1], OPTO_IN_2, INPUT_PULLUP);
	GpioInit(&inputs[2], OPTO_IN_3, INPUT_PULLUP);
	GpioInit(&inputs[3], OPTO_IN_4, INPUT_PULLUP);
	GpioInit(&inputs[4], OPTO_IN_5, INPUT_PULLUP);
	GpioInit(&inputs[5], OPTO_IN_6, INPUT_PULLUP);
	GpioInit(&inputs[6], OPTO_IN_7, INPUT_PULLUP);
	GpioInit(&inputs[7], OPTO_IN_8, INPUT_PULLUP);
	//outputs
	GpioInit(&outputs[0], RELE_1, OUTPUT);
	GpioInit(&outputs[1], RELE_2, OUTPUT);
	GpioInit(&outputs[2], RELE_3, OUTPUT);
	GpioInit(&outputs[3], RELE_4, OUTPUT);
	GpioInit(&outputs[4], RELE_5, OUTPUT);
	GpioInit(&outputs[5], RELE_6, OUTPUT);
	GpioInit(&outputs[6], RELE_7, OUTPUT);
	GpioInit(&outputs[7], RELE_8, OUTPUT);
	//gpios
	GpioInit(&gpios[0], A0, INPUT_PULLUP);
	GpioInit(&gpios[1], A1, INPUT_PULLUP);
	GpioInit(&gpios[2], A2, INPUT_PULLUP);
	GpioInit(&gpios[3], A3, INPUT_PULLUP);
	GpioInit(&gpios[4], A4, INPUT_PULLUP);
	GpioInit(&gpios[5], A5, INPUT_PULLUP);
	GpioInit(&gpios[6], A6, INPUT_PULLUP);
	GpioInit(&gpios[7], A7, INPUT_PULLUP);
	GpioInit(&gpios[8], A8, INPUT_PULLUP);
	GpioInit(&gpios[9], A9, INPUT_PULLUP);
	GpioInit(&gpios[10], A10, INPUT_PULLUP);
	GpioInit(&gpios[11], A11, INPUT_PULLUP);
	GpioInit(&gpios[12], A12, INPUT_PULLUP);
	GpioInit(&gpios[13], A13, INPUT_PULLUP);
	GpioInit(&gpios[14], A14, INPUT_PULLUP);
	GpioInit(&gpios[15], A15, INPUT_PULLUP);
}

void Board::GpioInit(Gpio_struct *gpio, char pin, char type)
{
	gpio->Pin = pin;
	gpio->Type = type;
	pinMode(pin, type);
	if (type == INPUT || type == INPUT_PULLUP)gpio->Input_delay = 100;
}






