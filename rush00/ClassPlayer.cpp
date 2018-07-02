#include "ClassPlayer.hpp"

Player	&Player::moveLeft(Player &obj)
{
	int c = 0;

	if (obj.getX() > 0 + 3)
	{
		obj.setX(obj.getX() - 3);
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
		{
			arrPoint[c].x -= 3;
			++c;
		}
	}
	return (*this);
}

Player	&Player::moveRight(Player &obj)
{
	int	c = 0;

	if (obj.getX() < windowWidth - 13)
	{
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
		{
			arrPoint[c].x += 3;
			++c;
		}
		obj.setX(obj.getX() + 3);
	}
	return (*this);

}

Player	&Player::moveUp(Player &obj)
{
	int c = 0;

	if (obj.getY() > moveLimit - 4)
	{
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
		{
			arrPoint[c].y -= 3;
			++c;
		}
		obj.setY(obj.getY() - 3);
	}
	return (*this);
}

Player	&Player::moveDown(Player &obj)
{
	int c = 0;
	if (obj.getY() < windowHeight - 11)
	{
		while (arrPoint[c].x != -99 && arrPoint[c].y != -99)
		{
			arrPoint[c].y += 3;
			++c;
		}
		obj.setY(obj.getY() + 3);
	}
	return (*this);
}


Player::Player(): Object()
{
	x = moveLimit + 2;
	y = windowHeight / 2;
	setObjectView();
	moveAllCoords();
	//std::cout << "Standart constructor of Player" << std::endl;
}

Player::Player(const Player &obj)
{
	*this = obj;
}

Player::~Player()
{
	//std::cout << "Destructor Player" << std::endl;
	delete [] objectView;
}

Player& Player::operator=(const Player &obj)
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


bool	Player::checkIfBottom()
{
	if (y + 10 >= windowHeight)
		return (false);
	return (true);
}




/*bool operator==(const Enemy &f)const
{
	if (this->x == f.getX() && this->y == f.getY())
	{

	}
}
 */

void	Player::setObjectView()
{
	objectView = new char*[12];
	objectView[0] = (char *)("   /\\ ");
	objectView[1] = (char *)("   \\#\\  ");
	objectView[2] = (char *)("    \\#\\ ");
	objectView[3] = (char *)("    /##\\ ");
	objectView[4] = (char *)("   <===>\\ ");
	objectView[5] = (char *)("   <####)> ");
	objectView[6] = (char *)("   <===>/ ");
	objectView[7] = (char *)("    \\##/ ");
	objectView[8] = (char *)("    /#/ ");
	objectView[9] = (char *)("   /#/ ");
	objectView[10] = (char *)("   \\/ ");
	objectView[11] = nullptr;
	arrPoint = convertViewToCoordinates();
}

void	Player::moveAllCoords()
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

bool Player::operator==(const Enemy &f)const
{
	int i;
	int	j;

	i = 0;
	while (this->arrPoint[i].x != -99 && this->arrPoint[i].y != -99)
	{
		j = 0;
		while (f.arrPoint[j].x != -99 && f.arrPoint[j].y != -99)
		{
			if (fabs(arrPoint[i].x - f.arrPoint[j].x) <= 0.5 && fabs(arrPoint[i].y - f.arrPoint[j].y) <= 0.5)
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}