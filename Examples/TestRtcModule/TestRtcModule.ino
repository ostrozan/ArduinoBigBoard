//#include "GPIO.h"



#include <GsmModule.h>
#include <GPIO.h>
#include <DateTime.h>
#include <Board.h>
Board board;
DateTime dateTime;
GsmModule gsm;

String buffer;
uint8_t c;
void setup()
{
	dateTime.Init();
	board.Init();
	board.SerialInit(BTserial,38400 );//9600
   //board.SerialInit(GSMserial, 9600);	board.SerialInit(RS485serial, 9600);
	board.Send(BTserial, "nastav datum a cas ve formatu \n DD.MM.RRRR-HH:MM:SS\n");

}
void loop()
{
	do
	{
	while (Serial.available() > 0)
		{
			c= Serial.read();
			if (c == '\n')
			{
				Serial.println("ok");
				SetDateTime(buffer);
			}
			else buffer += (char)c;
		}
	} while (c!='\n');
	
	dateTime.GetDateTime();
	board.Send(BTserial, dateTime.ToString() + '\n');
	delay(1000);
}

void SetDateTime(String buf)
{
	Serial.println(buf);
	dateTime.SetDateTime(buf);
	dateTime.GetDateTime();
	board.Send(BTserial, "nastaveny cas:  " + dateTime.ToString());
}


