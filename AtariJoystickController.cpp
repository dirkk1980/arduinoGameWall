#include "AtariJoystickController.h"


AtariJoystickController::AtariJoystickController()
{
	 buttonUpState = false;
	 buttonDownState = false;
	 buttonLeftState = false;
	 buttonRightState = false;
	 buttonPressed = false;
}

void AtariJoystickController::init(PinSetting pinSetting, SnakeModel model)
{
	this->pinSetting = pinSetting;
	this->model = model;
	pinMode(pinSetting.pinUp, INPUT);
	pinMode(pinSetting.pinDown, INPUT);
	pinMode(pinSetting.pinLeft, INPUT);
	pinMode(pinSetting.pinRight, INPUT);
}

void AtariJoystickController::update()
{
	buttonUpState = digitalRead(pinSetting.pinUp);
	buttonDownState = digitalRead(pinSetting.pinDown);
	buttonLeftState = digitalRead(pinSetting.pinLeft);
	buttonRightState = digitalRead(pinSetting.pinRight);

	if (buttonLeftState == HIGH || buttonDownState == HIGH || buttonRightState == HIGH || buttonUpState == HIGH)
	{
		if (buttonPressed == false)
		{
			if (buttonLeftState == HIGH)
			{
				model.moveLeft();
			}
			if (buttonDownState == HIGH)
			{
				model.moveDown();
			}
			if (buttonRightState == HIGH)
			{
				model.moveRight();
			}
			if (buttonUpState == HIGH)
			{
				model.moveUp();
			}
			buttonPressed = true;
		}
	}
	else
	{
		buttonPressed = false;
	}

}

