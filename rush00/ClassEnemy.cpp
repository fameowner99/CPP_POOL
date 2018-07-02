#include "ClassEnemy.hpp"

Enemy	&Enemy::moveLeft(Enemy &obj)
{
	int c = 0;
	static int s = 0;
	if (!obj.dead) {
		obj.setX(obj.getX() - 0.3 - s);
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99) {
			arrPoint[c].x -= 0.3 - s;
			++c;
		}
		s += 0.0005;
	}
	return (*this);
}

Enemy	&Enemy::moveRight(Enemy&obj)
{
	int c = 0;

	obj.setX(obj.getX() + 0.3);
	while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
	{
		arrPoint[c].x += 0.3;
		++c;
	}
	return (*this);

}

Enemy	&Enemy::moveUp(Enemy &obj)
{
	int c = 0;

	if (obj.getY() > 0)
	{
		obj.setY(obj.getY() - 1);
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
		{
			arrPoint[c].y -= 1;
			++c;
		}
	}
	return (*this);
}

Enemy	&Enemy::moveDown(Enemy &obj)
{
	int c = 0;

	if (obj.getY() < windowHeight - 5)
	{
		obj.setY(obj.getY() + 1);
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
		{
			arrPoint[c].y += 1;
			++c;
		}
	}
	return (*this);
}


Enemy::Enemy(): Object()
{

	x = windowWidth - 25;
	y = 0 ;
	dead = false;
	//std::cout << "Standart constructor of Enemy" << std::endl;
}

Enemy::Enemy(const Enemy &obj)
{
	*this = obj;
}

Enemy::~Enemy()
{
	//std::cout << "Destructor Enemy" << std::endl;
	//delete [] objectView;
}

Enemy& Enemy::operator=(const Enemy &obj)
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

void	Enemy::setObjectView()
{
	objectView = new char*[5];
	objectView[0] = (char *)("        //-A-\\");
	objectView[1] = (char *)("  ___---=======---___");
	objectView[2] = (char *)("(=__\\###/.. ..\\###/__=)");
	objectView[3] = (char *)("     ---\\__O__/---");
	objectView[4] = nullptr;
	arrPoint = convertViewToCoordinates();
}

void	Enemy::moveAllCoords()
{
	int i;

	i = 0;
	while (arrPoint[i].x != -99 && arrPoint[i].y != -99)
	{
		arrPoint[i].x += x;
		arrPoint[i].y += y;
		++i;
	}
}



/*bool operator==(const Enemy &f)const
{
	if (this->x == f.getX() && this->y == f.getY())
	{

	}
}
 */
