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

	MatrixController.setPixel(0, 0);
	MatrixController.setPixel(1, 1);
	MatrixController.setPixel(1, 3);
	MatrixController.setPixel(2, 2);
	MatrixController.setPixel(3, 1);
	MatrixController.setPixel(3, 2);
}

void loop()
{
	buttonUpState = digitalRead(BUTTON_UP_PIN);
	buttonDownState = digitalRead(BUTTON_DOWN_PIN);
	buttonLeftState = digitalRead(BUTTON_LEFT_PIN);
	buttonRightState = digitalRead(BUTTON_RIGHT_PIN);
	if (buttonLeftState == HIGH)
	{
	}
	if (buttonDownState == HIGH)
	{
	}
	if (buttonRightState == HIGH)
	{
	}
	if (buttonUpState == HIGH)
	{
	}
	MatrixController.update();
	delay(50);
}


