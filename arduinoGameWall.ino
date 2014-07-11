#include "AtariJoystickController.h"
#include "MatrixController.h"
#include "SnakeModel.h"

//const byte BUTTON_UP_PIN = 2;
//const byte BUTTON_LEFT_PIN = 3;
//const byte BUTTON_DOWN_PIN = 4;
//const byte BUTTON_RIGHT_PIN = 5;

const byte CLOCK_PIN = A0;
const byte LATCH_PIN = A1;
const byte DATA_PIN = A2;

//piso register
const byte SERIAL_IN_PIN = 2;
const byte CP_PIN = 3;
const byte PL_PIN = 4;

int i;

SnakeModel snakeModelPlayer1;
AtariJoystickController joystickControllerPlayer1;
MatrixController matrix1;

void setup()
{
	AtariJoystickController::PinSetting joystickPinsP1 = { SERIAL_IN_PIN, CP_PIN, PL_PIN };
	joystickControllerPlayer1.init(joystickPinsP1, snakeModelPlayer1);
	MatrixController::PinSetting matrixPins = { LATCH_PIN, CLOCK_PIN, DATA_PIN };
	matrix1.init(matrixPins);
	snakeModelPlayer1.setPos(2, 2);
}

void loop()
{
	joystickControllerPlayer1.update();
	matrix1.clearAll();
	matrix1.setPixel(snakeModelPlayer1.pSnakeHead->rowIndex, snakeModelPlayer1.pSnakeHead->colIndex, true);
	matrix1.update();
	delay(4);
}


