


#include <GsmModule.h>
#include <GPIO.h>
#include <DateTime.h>
#include <Board.h>
#define DEBUG_MODE

#define sendSmsPin A0
Board board;
DateTime dateTime;
GsmModule gsm;

char pom, pom1;
int delayInp;
bool blok,blok1,blok2,blok3,blok4,blok5;
char *myNumber = "777622530";
void setup()
{
	dateTime.Init();
	board.Init();

	board.SerialInit(BTserial, 38400);
	board.SerialInit(GSMserial, 9600);
	board.SerialInit(RS485serial, 9600);
	//board.CANInit(CAN_500KBPS);
	if (gsm.Init())board.Send(BTserial, "gsm OK\n\n");
	else board.Send(BTserial, "gsm fail\n\n");
}

void loop()
{
	
	if (digitalRead(A0)==LOW && blok==false)
	{
		blok = true;
		board.Send(BTserial, "POSILAM SMS NA CISLO ");
		board.Send(BTserial, myNumber);
		if(gsm.Sms(myNumber, "TEST sms"))Serial.println(" SMS OK");
		else board.Send(BTserial, " SMS fail");
	
	}

	if (digitalRead(A1) == LOW && blok1 == false)
	{
		blok1 = true;
		board.Send(BTserial, "VOLAM CISLO ");
		board.Send(BTserial,myNumber + '\n');
		if (gsm.Call(myNumber))board.Send(BTserial, " call OK\n");
		else board.Send(BTserial, " call fail\n");
	}

	if (digitalRead(A15) == LOW && blok2 == false)
	{
		blok2 = true;
		board.Send(BTserial, "ZAVESUJI\n");
		if (gsm.HangOut())board.Send(BTserial, " hangout OK\n");
		else board.Send(BTserial, " hangout fail\n");
	}

	if (digitalRead(A2) == LOW && blok3 == false)
	{
		blok3 = true;
		board.Send(BTserial, "SIGNAL: ");
		board.Send(BTserial, gsm.Signal()+'\n');
		
	}
	if (digitalRead(A3) == LOW && blok4 == false)
	{
		blok4 = true;
		board.Send(BTserial, "OPERATOR: ");
		board.Send(BTserial, gsm.Operator() + '\n');
	}

	if (digitalRead(A4) == LOW && blok5 == false)
	{
		blok5 = true;
		board.Send(BTserial, "CAS: ");
		board.Send(BTserial, gsm.ReadRTC() + '\n');
	}


}


