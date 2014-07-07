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

public:
	void init(short latchPin, short clockPin, short dataPin);
	void setPixel(short rowIndex, short coLIndex, bool status);
	void update();
	void clearAll();
	static const short MATRIX_SIZE = 4;

private:
	short latchPin;
	short clockPin;
	short dataPin;
	bool pixels[MATRIX_SIZE][MATRIX_SIZE];
	byte dataToSend;
	short lastRenderedRow;
};

extern MatrixControllerClass MatrixController;

#endif

