#include "AtariJoystickController.h"

void AtariJoystickControllerClass::init(short pinUp, short pinDown, short pinLeft, short pinRight)
{
	pinMode(pinUp, INPUT);
	pinMode(pinDown, INPUT);
	pinMode(pinLeft, INPUT);
	pinMode(pinRight, INPUT);
}


AtariJoystickControllerClass AtariJoystickController;

