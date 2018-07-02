#ifndef CLASSPLAYER_HPP

# define CLASSPLAYER_HPP

# include "ClassObject.hpp"
# include "ClassEnemy.hpp"



class Player: public virtual Object
{
private:
	void	setObjectView();
	void	moveAllCoords();

public:
	bool operator==(const Enemy &f)const;
	Player	&moveLeft(Player&);
	Player	&moveRight(Player&);
	Player	&moveUp(Player&);
	Player	&moveDown(Player&);
	Player();
	Player(const Player&);
	~Player();
	Player&operator=(const Player&);
	//bool operator==(const Enemy &f)const;
	bool	checkIfBottom();
};

#endif