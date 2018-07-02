#include "ClassObject.hpp"

Object::Object(): x(0), y(0), healthPoints(1), maxHealthPoints(1)
{

	//std::cout << "Constructor of Object" << std::endl;
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	windowHeight = w.ws_row;
	windowWidth = w.ws_col;
	objectView = nullptr;
	arrPoint = nullptr;

}

Object::~Object()
{
	delete [] arrPoint;
	//std::cout << "Destructor of Object" << std::endl;
}

Object::Object(const Object &obj)
{
	*this = obj;
}

Object &Object::operator=(const Object &obj)
{
	if (this != &obj)
	{
		x = obj.x;
		y = obj.y;
		healthPoints = obj.healthPoints;
		maxHealthPoints = obj.maxHealthPoints;
	}
	return (*this);
}

void 	Object::setX(const float &x)
{
	this->x = x;
}

float		Object::getX()const
{
	return (x);
}

void 	Object::setY(const float &y)
{
	this->y = y;
}

float	Object::getY()const
{
	return (y);
}

Point	*Object::convertViewToCoordinates()
{
	int x;
	int y;
	int c;

	c = 0;
	y = 0;
	while (objectView[y])
	{
		x = 0;
		while (objectView[y][x])
		{
			++c;
			++x;
		}
		++y;
	}
	arrPoint = new Point[c + 1];
	c = 0;
	y = 0;
	while (objectView[y])
	{
		x = 0;
		while (objectView[y][x])
		{
			if (objectView[y][x] != ' ')
			{
				arrPoint[c].y = y;
				arrPoint[c].x = x;
				++c;
			}
			++x;
		}
		++y;
	}
	arrPoint[c].x = -99;
	arrPoint[c].y = -99;
	return  (arrPoint);
}
