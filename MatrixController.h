// MatrixController.h

#ifndef _MATRIXCONTROLLER_h
#define _MATRIXCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class MatrixController
{
public:
	struct PinSetting
	{
		byte latchPin;
		byte clockPin;
		byte dataPin;
	};
	void init(PinSetting pinSetting);
	void setPixel(short rowIndex, short coLIndex, bool status);
	void update();
	void clearAll();
	static const short MATRIX_SIZE = 4;

private:
	bool pixels[MATRIX_SIZE][MATRIX_SIZE];
	byte dataToSend;
	short lastRenderedRow;
	PinSetting pinSetting;
};
#endif

