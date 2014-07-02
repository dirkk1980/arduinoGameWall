#include "MatrixController.h"
#include "SnakeModel.h";

const short BUTTON_UP_PIN = 2;
const short BUTTON_DOWN_PIN = 4;
const short BUTTON_LEFT_PIN = 3;
const short BUTTON_RIGHT_PIN = 5;

bool buttonUpState = false;
bool buttonDownState = false;
bool buttonLeftState = false;
bool buttonRightState = false;


//looping variables
short i;
short j;

SnakeModel snake;

void setup()
{
	pinMode(BUTTON_UP_PIN, INPUT);
	pinMode(BUTTON_DOWN_PIN, INPUT);
	pinMode(BUTTON_LEFT_PIN, INPUT);
	pinMode(BUTTON_RIGHT_PIN, INPUT);

	MatrixController.init(A1, A0, A2);

	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			MatrixController.setPixel(i, j);
		}
	}
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
		//snake.posX++;
		//MatrixController.setPixel(snake.posX, snake.posY);
	}
	MatrixController.update();
	delay(500);
}


