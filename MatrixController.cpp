#include "MatrixController.h"

void MatrixControllerClass::init(short latchPin, short clockPin, short dataPin)
{
	this->latchPin = latchPin;
	this->clockPin = clockPin;
	this->dataPin = dataPin;
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	lastRenderedRow = 0;
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			pixels[i][j] = false;
		}
	}
}

MatrixControllerClass MatrixController;

void MatrixControllerClass::setPixel(short rowIndex, short colIndex, bool status)
{
	pixels[rowIndex][colIndex] = status;
}

void MatrixControllerClass::update()
{
	if (lastRenderedRow == MATRIX_SIZE)
	{
		lastRenderedRow = 0;
	}
	for (int i = lastRenderedRow; i < MATRIX_SIZE; i++){
		dataToSend = B11110000;
		for (int j = 0; j < MATRIX_SIZE; j++){
			if (pixels[i][j] == true)
			{
				bitWrite(dataToSend, i, 1);
				bitWrite(dataToSend, j + MATRIX_SIZE, 0);
			}
		}
		digitalWrite(latchPin, LOW);
		shiftOut(dataPin, clockPin, MSBFIRST, dataToSend);
		digitalWrite(latchPin, HIGH);
		lastRenderedRow++;
		return;
	}
}

void MatrixControllerClass::clearAll()
{
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			pixels[i][j] = false;
		}
	}
}