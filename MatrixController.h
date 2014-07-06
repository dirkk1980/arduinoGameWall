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
	void setPixel(short xPos, short yPos);
	void update();
	static const short MATRIX_SIZE = 4;

private:
	struct Pixel
	{
		bool on;
		bool rendered;
	};
	short latchPin;
	short clockPin;
	short dataPin;
	Pixel pixels[MATRIX_SIZE][MATRIX_SIZE];
	byte dataToSend;
	short remainingPixels;
};

extern MatrixControllerClass MatrixController;

#endif

