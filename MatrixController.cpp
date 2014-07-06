#include "MatrixController.h"

void MatrixControllerClass::init(short latchPin, short clockPin, short dataPin)
{
	this->latchPin = latchPin;
	this->clockPin = clockPin;
	this->dataPin = dataPin;
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	remainingPixels = 0;
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			pixels[i][j].on = false;
			pixels[i][j].rendered = false;
		}
	}
}

MatrixControllerClass MatrixController;

void MatrixControllerClass::setPixel(short row, short col)
{
	pixels[row][col] = true;
}

void MatrixControllerClass::update()
{
	//check how many pixels are left in matrix to be rendered
	remainingPixels = 0;
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			if (pixels[i][j].on == true && pixels[i][j].rendered == false)
			{
				remainingPixels++;
			}
		}
	}

	//render next pixel
	for (int i = 0; i < MATRIX_SIZE; i++){
		for (int j = 0; j < MATRIX_SIZE; j++){
			if (pixels[i][j].on == true && pixels[i][j].rendered == false)
			{
				//check if this is the last pixel to render, if yes -> reset all render states
				if (remainingPixels <= 1)
				{
					for (int i = 0; i < MATRIX_SIZE; i++){
						for (int j = 0; j < MATRIX_SIZE; j++){
							pixels[i][j].rendered = false;
						}
					}
				}
				else
				{
					pixels[i][j].rendered = true;
				}
		
				dataToSend = B11110000;
				bitWrite(dataToSend, i, 1);
				bitWrite(dataToSend, j + MATRIX_SIZE, 0);
				digitalWrite(latchPin, LOW);
				shiftOut(dataPin, clockPin, MSBFIRST, dataToSend);
				digitalWrite(latchPin, HIGH);
				return;
			}
		}
	}
}