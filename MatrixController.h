// MatrixController.h

#ifndef _MATRIXCONTROLLER_h
#define _MATRIXCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class MatrixControllerClass
{
protected:


public:
	void init(short latchPin, short clockPin, short dataPin);
	void setPixel(short xPos, short yPos);
	void update();

private:
	short latchPin;
	short clockPin;
	short dataPin;
	short i;
	short j;
	bool ledStatus[4][4];
	byte dataToSend;
};

extern MatrixControllerClass MatrixController;

#endif

