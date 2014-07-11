#ifndef _ATARIJOYSTICKCONTROLLER_h
#define _ATARIJOYSTICKCONTROLLER_h

#include "SnakeModel.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class AtariJoystickController
{

public:
	AtariJoystickController();
	struct PinSetting
	{
		byte pinSerialIn;
		byte pinCP;
		byte pinPL;
	};
	void init(PinSetting pinSetting,SnakeModel model);
	void update();
private:
	SnakeModel model;
	PinSetting pinSetting;
	bool buttonUpState;
	bool buttonDownState;
	bool buttonLeftState;
	bool buttonRightState;
	bool buttonPressed;
};
#endif

