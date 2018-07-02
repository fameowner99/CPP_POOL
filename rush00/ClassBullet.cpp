#include "ClassBullet.hpp"

Bullet	&Bullet::moveLeft(Bullet &obj)
{

	obj.setX(obj.getX() - 0.5f);
	obj.arrPoint[0].x -= 0.5f;
	return (*this);
}

Bullet	&Bullet::moveRight(Bullet &obj)
{


		obj.setX(obj.getX() + 0.5f);
		obj.arrPoint[0].x += 0.5f;

	return (*this);

}

Bullet::~Bullet()
{
	//delete point
}

Bullet::Bullet(): Object()
{

}

Bullet::Bullet(const Bullet&): Object()
{

}


Bullet& Bullet::operator=(const Bullet &obj)
{
	if (this != &obj)
	{
		x = obj.x;
		y = obj.y;
	}
	return (*this);
}

Bullet::Bullet(const Player &player)
{
	x = player.getX();
	y = player.getY();
}

static bulletList	*bulletListNew(const Player &player)
{
	bulletList		*res;

	res = new bulletList;
	res->bul = new Bullet(player);
	res->bul->arrPoint = new Point;
	res->bul->arrPoint[0].x = player.getX() + 10;
	res->bul->arrPoint[0].y = player.getY() + 5;
	res->next = NULL;
	return (res);
}

bulletList			*bulletPushBack(bulletList *head, const Player &player)
{
	bulletList		*tmp;
	bulletList		*last;

	if (!head)
		return bulletListNew(player);
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		last = bulletListNew(player);
		tmp->next = last;
	}
	return (head);
}
