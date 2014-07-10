#include "SnakeModel.h"

SnakeModel::SnakeModel()
{
	pSnakeHead = &snakeElements[0];
}

SnakeModel::~SnakeModel()
{
}

void SnakeModel::setPos(byte rowIndex, byte colIndex)
{
	pSnakeHead->rowIndex = rowIndex;
	pSnakeHead->colIndex = colIndex;
}

void SnakeModel::moveUp()
{
	if (pSnakeHead->rowIndex == 0)
	{
		pSnakeHead->rowIndex = MATRIX_SIZE - 1;
	}
	else
	{
		pSnakeHead->rowIndex = pSnakeHead->rowIndex--;
	}
}
void SnakeModel::moveDown()
{
	if (pSnakeHead->rowIndex == MATRIX_SIZE - 1)
	{
		pSnakeHead->rowIndex = 0;
	}
	else
	{
		pSnakeHead->rowIndex++;
	}
}
void SnakeModel::moveRight()
{
	if (pSnakeHead->colIndex == 0)
	{
		pSnakeHead->colIndex = MATRIX_SIZE - 1;
	}
	else
	{
		pSnakeHead->colIndex--;
	}
}
void SnakeModel::moveLeft()
{
	if (pSnakeHead->colIndex == MATRIX_SIZE - 1)
	{
		pSnakeHead->colIndex = 0;
	}
	else
	{
		pSnakeHead->colIndex++;
	}
}
