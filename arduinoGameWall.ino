const byte BUTTON_UP_PIN = 3;
const byte BUTTON_DOWN_PIN = 4;
const byte BUTTON_LEFT_PIN = 2;
const byte BUTTON_RIGHT_PIN = 5;

byte buttonUpState = 0;
byte buttonDownState = 0;
byte buttonLeftState = 0;
byte buttonRightState = 0;



#define latchPin A1
#define clockPin A0
#define dataPin A2


//Pin connected to ST_CP of 74HC595
//int latchPin = 9;
//Pin connected to SH_CP of 74HC595
//int clockPin = 8;
//Pin connected to DS of 74HC595
//int dataPin = 10;

//looping variables
byte i;
byte j;

//storage variable
byte dataToSend;

//storage for led states, 4 bytes
byte ledData1[] = { 1, 1, 1, 1 };
byte ledData2[] = { 2, 2, 2, 2 };
byte ledData3[] = { 1, 3, 7, 15 };
byte ledData4[] = { 1, 3, 7, 15 };

void setup()
{
	pinMode(BUTTON_UP_PIN, INPUT);
	pinMode(BUTTON_DOWN_PIN, INPUT);
	pinMode(BUTTON_LEFT_PIN, INPUT);
	pinMode(BUTTON_RIGHT_PIN, INPUT);

	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);

}

void loop()
{
	buttonUpState = digitalRead(BUTTON_UP_PIN);
	buttonDownState = digitalRead(BUTTON_DOWN_PIN);
	buttonLeftState = digitalRead(BUTTON_LEFT_PIN);
	buttonRightState = digitalRead(BUTTON_RIGHT_PIN);
	if (buttonLeftState == HIGH )
	{
		pyramid(ledData1);
	}
	if (buttonDownState == HIGH)
	{
		//pyramid();
	}
	if (buttonRightState == HIGH)
	{
		//pyramid();
	}
	if (buttonUpState == HIGH)
	{
		pyramid(ledData2);
	}
}

void pyramid(byte lData[]) {
	for (i = 0; i<4; i++){

		//send data from ledData to each row, one at a time
		byte dataToSend = (1 << (i + 4)) | (15 & ~lData[i]);

		// setlatch pin low so the LEDs don't change while sending in bits
		digitalWrite(latchPin, LOW);

		//    // shift out the bits of dataToSend to the 74HC595
		//    shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
		// the code below is the equivalent of the two lines above
		for (j = 0; j<8; j++){
			digitalWrite(clockPin, LOW);
			digitalWrite(dataPin, ((dataToSend >> j) & 1));
			digitalWrite(clockPin, HIGH);
		}


		//set latch pin high- this sends data to outputs so the LEDs will light up
		digitalWrite(latchPin, HIGH);
		delay(200);//wait
	}
}
