#ifndef CLASSENEMY_HPP

# define CLASSENEMY_HPP
# include "ClassObject.hpp"

class Enemy: public virtual Object
{
	private:

	public:
	bool	dead;
	Enemy &setH(float y, Enemy&);
	void	setObjectView();
	void	moveAllCoords();
	Enemy &moveLeft(Enemy &);
	Enemy &moveRight(Enemy &);
	Enemy &moveUp(Enemy &);
	Enemy &moveDown(Enemy &);
	Enemy();
	Enemy(const Enemy &);
	~Enemy();
	Enemy &operator=(const Enemy &);
	//bool operator==(const Enemy &f)const;
	//bool	checkIfBottom();
};

#endif