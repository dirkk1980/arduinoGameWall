// AtariJoystickController.h

#ifndef _ATARIJOYSTICKCONTROLLER_h
#define _ATARIJOYSTICKCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class AtariJoystickControllerClass
{
 protected:


 public:
	 void init(short pinUp, short pinDown, short pinLeft, short pinRight);
};

extern AtariJoystickControllerClass AtariJoystickController;

#endif

