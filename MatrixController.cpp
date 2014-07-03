#include "MatrixController.h"

void MatrixControllerClass::init(short latchPin, short clockPin, short dataPin)
{
	this->latchPin = latchPin;
	this->clockPin = clockPin;
	this->dataPin = dataPin;
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	lastActiveRow = -1;
	lastActiveCol = -1;
	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++){
		for (colIndex = 0; colIndex < MATRIX_SIZE; colIndex++){
			ledStatus[rowIndex][colIndex] = false;
		}
	}
}

MatrixControllerClass MatrixController;

void MatrixControllerClass::setPixel(short rowPos, short colPos)
{
	ledStatus[rowPos][colPos] = true;
}

void MatrixControllerClass::update()
{
	if (lastActiveRow > 0 )
	{
		rowIndex = lastActiveRow;
	}
	else
	{
		rowIndex = 0;
	}
	for (rowIndex; rowIndex < MATRIX_SIZE; rowIndex++){
		for (colIndex = 0; colIndex < MATRIX_SIZE; colIndex++){
			if (ledStatus[rowIndex][colIndex] == true && (rowIndex > lastActiveRow || colIndex > lastActiveCol))
			{
				dataToSend = B11110000;
				bitWrite(dataToSend, rowIndex, 1);
				bitWrite(dataToSend, colIndex + MATRIX_SIZE, 0);
				lastActiveRow = rowIndex;
				lastActiveCol = colIndex;
				digitalWrite(latchPin, LOW);
				shiftOut(dataPin, clockPin, MSBFIRST, dataToSend);
				digitalWrite(latchPin, HIGH);
				return;
			}
		}
	}
	// loop do not execute return, so array was searched complete
	lastActiveRow = -1;
	lastActiveCol = -1;
}