#include "MatrixController.h"
#include "SnakeModel.h"

const short BUTTON_UP_PIN = 2;
const short BUTTON_DOWN_PIN = 4;
const short BUTTON_LEFT_PIN = 3;
const short BUTTON_RIGHT_PIN = 5;

bool buttonUpState = false;
bool buttonDownState = false;
bool buttonLeftState = false;
bool buttonRightState = false;

bool buttonPressed = false;

SnakeModel snakeModel;

void setup()
{
	pinMode(BUTTON_UP_PIN, INPUT);
	pinMode(BUTTON_DOWN_PIN, INPUT);
	pinMode(BUTTON_LEFT_PIN, INPUT);
	pinMode(BUTTON_RIGHT_PIN, INPUT);

	MatrixController.init(A1, A0, A2);

	snakeModel.matrixSize = 4;
	snakeModel.setPos(2,2);
	MatrixController.setPixel(snakeModel.posX, snakeModel.posY, true);
}

void loop()
{
	buttonUpState = digitalRead(BUTTON_UP_PIN);
	buttonDownState = digitalRead(BUTTON_DOWN_PIN);
	buttonLeftState = digitalRead(BUTTON_LEFT_PIN);
	buttonRightState = digitalRead(BUTTON_RIGHT_PIN);
	
	if (buttonLeftState == HIGH || buttonDownState == HIGH || buttonRightState == HIGH || buttonUpState == HIGH)
	{
		if (buttonPressed == false)
		{
			if (buttonLeftState == HIGH)
			{
				snakeModel.moveLeft();
			}
			if (buttonDownState == HIGH)
			{
				snakeModel.moveDown();
			}
			if (buttonRightState == HIGH)
			{
				snakeModel.moveRight();
			}
			if (buttonUpState == HIGH)
			{
				snakeModel.moveUp();
			}
			buttonPressed = true;
		}
	}
	else
	{
		buttonPressed = false;
	}

	
	MatrixController.clearAll();
	MatrixController.setPixel(snakeModel.posX, snakeModel.posY, true);
	MatrixController.update();
	delay(4);
}


