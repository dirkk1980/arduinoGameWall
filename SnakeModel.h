#ifndef _SNAKEMODEL_h
#define _SNAKEMODEL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class SnakeModel
{
	struct SnakeElement
	{
		byte colIndex;
		byte rowIndex;
		byte lastCol;
		byte lastRow;
	};
public:
	SnakeModel();
	~SnakeModel();
	SnakeElement snakeElements[1];
	struct SnakeElement *pSnakeHead;
	static const short MATRIX_SIZE = 4;
	void setPos(byte rowIndex, byte colIndex);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};
#endif
