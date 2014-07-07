#include "SnakeModel.h"

SnakeModel::SnakeModel()
{

}


SnakeModel::~SnakeModel()
{
}

void SnakeModel::setPos(short xPos, short yPos)
{
	this->posX = xPos;
	this->posY = yPos;
}

void SnakeModel::moveUp()
{
	if (posX == 0)
	{
		posX = matrixSize - 1;
	}
	else
	{
		posX = posX--;
	}
}
void SnakeModel::moveDown()
{
	if (posX == matrixSize - 1)
	{
		posX = 0;
	}
	else
	{
		posX++;
	}
}
void SnakeModel::moveRight()
{
	if (posY == 0)
	{
		posY = matrixSize -1;
	}
	else
	{
		posY--;
	}
}
void SnakeModel::moveLeft()
{
	if (posY == matrixSize - 1)
	{
		posY = 0;
	}
	else
	{
		posY++;
	}
}
