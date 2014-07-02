#include "MatrixController.h"

void MatrixControllerClass::init(short latchPin, short clockPin, short dataPin)
{
	this->latchPin = latchPin;
	this->clockPin = clockPin;
	this->dataPin = dataPin;
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	lastActiveI = -1;
	lastActiveJ = -1;
	for (i = 0; i < MATRIX_SIZE; i++){
		for (j = 0; j < MATRIX_SIZE; j++){
			ledStatus[i][j] = false;
		}
	}
}

MatrixControllerClass MatrixController;

void MatrixControllerClass::setPixel(short xPos, short yPos)
{
	ledStatus[xPos][yPos] = true;
}

void MatrixControllerClass::update()
{

	for (i = 0; i < MATRIX_SIZE; i++){
		for (j = 0; j < MATRIX_SIZE; j++){
			if (ledStatus[i][j] == true && (i > lastActiveI || j > lastActiveJ))
			{
				dataToSend = B11110000;
				bitWrite(dataToSend, i, 1);
				bitWrite(dataToSend, j + MATRIX_SIZE, 0);
				lastActiveI = i;
				lastActiveJ = j;
				digitalWrite(latchPin, LOW);
				shiftOut(dataPin, clockPin, MSBFIRST, dataToSend);
				digitalWrite(latchPin, HIGH);
				return;
			}
		}
	}
	// loop do not execute return, so array was searched complete
	lastActiveI = -1;
	lastActiveJ = -1;

}