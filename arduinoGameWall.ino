#include "MatrixController.h"

const short BUTTON_UP_PIN = 2;
const short BUTTON_DOWN_PIN = 4;
const short BUTTON_LEFT_PIN = 3;
const short BUTTON_RIGHT_PIN = 5;

bool buttonUpState = false;
bool buttonDownState = false;
bool buttonLeftState = false;
bool buttonRightState = false;

void setup()
{
	pinMode(BUTTON_UP_PIN, INPUT);
	pinMode(BUTTON_DOWN_PIN, INPUT);
	pinMode(BUTTON_LEFT_PIN, INPUT);
	pinMode(BUTTON_RIGHT_PIN, INPUT);

	MatrixController.init(A1, A0, A2);

	MatrixController.setPixel(2,2);
}

void loop()
{
	buttonUpState = digitalRead(BUTTON_UP_PIN);
	buttonDownState = digitalRead(BUTTON_DOWN_PIN);
	buttonLeftState = digitalRead(BUTTON_LEFT_PIN);
	buttonRightState = digitalRead(BUTTON_RIGHT_PIN);
	if (buttonLeftState == HIGH)
	{
		MatrixController.setPixel(2, 3);
	}
	if (buttonDownState == HIGH)
	{
		MatrixController.setPixel(3, 2);
	}
	if (buttonRightState == HIGH)
	{
		MatrixController.setPixel(2, 1);
	}
	if (buttonUpState == HIGH)
	{
		MatrixController.setPixel(1,2);
	}
	MatrixController.update();
}


