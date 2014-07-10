#include "MatrixController.h"

void MatrixController::init(PinSetting pinSetting)
{
	this->pinSetting = pinSetting;
	pinMode(pinSetting.latchPin, OUTPUT);
	pinMode(pinSetting.clockPin, OUTPUT);
	pinMode(pinSetting.dataPin, OUTPUT);
	lastRenderedRow = 0;
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			pixels[i][j] = false;
		}
	}
}

void MatrixController::setPixel(short rowIndex, short colIndex, bool status)
{
	pixels[rowIndex][colIndex] = status;
}

void MatrixController::update()
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
		digitalWrite(pinSetting.latchPin, LOW);
		shiftOut(pinSetting.dataPin, pinSetting.clockPin, MSBFIRST, dataToSend);
		digitalWrite(pinSetting.latchPin, HIGH);
		lastRenderedRow++;
		return;
	}
}

void MatrixController::clearAll()
{
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			pixels[i][j] = false;
		}
	}
}