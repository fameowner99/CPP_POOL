#ifndef CLASSBULLET_HPP

# define CLASSBULLET_HPP

#include "ClassPlayer.hpp"


class Bullet: public virtual Object
{
	public:
	Bullet	&moveLeft(Bullet&);
	Bullet	&moveRight(Bullet&);
	Bullet();
	Bullet(const Player&);
	Bullet(const Bullet&);
	~Bullet();
	Bullet&operator=(const Bullet&);
	//bool operator==(const Bullet &f)const;
};

struct		bulletList
{
	Bullet		*bul;
	bulletList	*next;
};

bulletList		*bulletPushBack(bulletList *head, const Player &player);
void			clearList(bulletList *head);

#endif