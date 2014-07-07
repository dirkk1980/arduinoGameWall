#ifndef _SNAKEMODEL_h
#define _SNAKEMODEL_h
#endif

class SnakeModel
{
public:
	SnakeModel();
	~SnakeModel();
	short posX;
	short posY;
	short matrixSize;
	void setPos(short xPos, short yPos);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
private:

};

