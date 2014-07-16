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
	pinMode(pinSetting.pinSerialIn, INPUT);
	pinMode(pinSetting.pinCP, OUTPUT);
	pinMode(pinSetting.pinPL, OUTPUT);

	digitalWrite(pinSetting.pinPL, HIGH);
	digitalWrite(pinSetting.pinCP, LOW);

	Serial.begin(115200);

	

	////read the switches 10 times to prove
	////that the system is stable
	//for (i = 0; i < 10; i++)
	//{
	//	//load logic bits from the DIP switches
	//	digitalWrite(pinSetting.pinPL, LOW);  //LOAD BITS
	//	//reset "load" line, this freezes the internal buffer on both chips
	//	digitalWrite(pinSetting.pinPL, HIGH);

	//	for (j = 0; j < 8; j++)
	//	{
	//		value = digitalRead(pinSetting.pinSerialIn);

	//		//read next "switch"
	//		digitalWrite(pinSetting.pinCP, HIGH);
	//		digitalWrite(pinSetting.pinCP, LOW);

	//		//print switch's value
	//		Serial.print(value);
	//	}

	//	Serial.println("");
	//	Serial.println("----------------");
	//	delay(200);
	//}
}

void AtariJoystickController::update()
{
	Serial.println("----------------");
	int i;
	int j;
	byte value;

	//load logic bits from the DIP switches
	//digitalWrite(pinSetting.pinPL, LOW);  //LOAD BITS
	//reset "load" line, this freezes the internal buffer on both chips
	digitalWrite(pinSetting.pinPL, HIGH);
	value = shiftIn(pinSetting.pinSerialIn, pinSetting.pinCP, MSBFIRST);
	digitalWrite(pinSetting.pinPL, LOW);
	//for (j = 0; j < 8; j++)
	//{
	//	value = digitalRead(pinSetting.pinSerialIn);

	//	//read next "switch"
	//	digitalWrite(pinSetting.pinCP, HIGH);
	//	digitalWrite(pinSetting.pinCP, LOW);
	//	
	//	//print switch's value
	//	Serial.print(value);
	//}
	Serial.print(value);

	/*buttonUpState = digitalRead(pinSetting.pinUp);
	buttonDownState = digitalRead(pinSetting.pinDown);
	buttonLeftState = digitalRead(pinSetting.pinLeft);
	buttonRightState = digitalRead(pinSetting.pinRight);*/

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

