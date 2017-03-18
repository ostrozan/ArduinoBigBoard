//#include "GPIO.h"





#include "Board.h"



#define sendSmsPin A0
Board board;
DateTime dateTime;
GsmModule gsm;

char pom, pom1;
int delayInp;
bool blok,blok1,blok2,blok3,blok4;
void setup()
{
	dateTime.Init();
	board.Init();
	//uncomment if not used
	//Serial.begin(9600);
	//board.BTinit(9600);
	//board.GSMinit(9600);
    //board.RS485init(9600);
	board.CANInit(CAN_500KBPS);
}

void loop()
{
	
	if (digitalRead(A0)==LOW && blok==false)
	{
		
	}

	if (digitalRead(A1) == LOW && blok1 == false)
	{
		blok1 = true;
		Serial.println("VOLAM");
		if (gsm.Call("777622530"))Serial.println(" call OK");
		else Serial.println(" call fail");
	}

	if (digitalRead(A15) == LOW && blok2 == false)
	{
		blok2 = true;
		Serial.println("ZAVESUJI");
		if (gsm.HangOut())Serial.println(" hangout OK");
		else Serial.println(" hang fail");
	}

	if (digitalRead(A2) == LOW && blok3 == false)
	{
		blok3 = true;
		Serial.println("SIGNAL");
		Serial.println(gsm.Signal());
		
	}
	if (digitalRead(A3) == LOW && blok4 == false)
	{
		blok4 = true;
		Serial.println("OPERATOR");
		Serial.println(gsm.Operator());

	}


}


