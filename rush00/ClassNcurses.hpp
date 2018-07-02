#ifndef CLASSNCURSES_HPP

# define CLASSNCURSES_HPP

# include <ncurses.h>
# include <iostream>
# include "ClassObject.hpp"
# include <sys/ioctl.h>
# include <unistd.h>
# include "ClassPlayer.hpp"
# include "ClassBullet.hpp"

class Ncurses:  public Enemy, public Player
{
	private:
		int 	numEnemy;
		void	draw_frame();
		void	printObject(Player&);
		Player	player;
		Enemy	*enemy;
	 	bulletList *bList;
		void	printObject(Enemy&);
		void	chooseMove(int key);
		void	loop();
		void	chooseCoordinates();
		void	printBullets();
		void	moveBullets();
		void	createNewEnemies();
		void	moveEnemies();
		void	printEnemies();
		bool	checkBoom();
		bool	checkIfBulletHitEnemy();
		bool	checkIfNew();
		void	printStat();
		static int 	numLife;
		void	gameOver();
		void	boom();
		static int score;

	public:
		Ncurses();


};

#endif