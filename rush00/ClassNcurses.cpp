#include "ClassNcurses.hpp"

int 	Ncurses::numLife = 4;
int 	Ncurses::score = 0;
Ncurses::Ncurses(): Object(), Player()
{
	//std::cout << "constructor of NCURSES" << std::endl;
	bList = NULL;
	enemy = NULL;
	loop();
}

void	Ncurses::draw_frame()
{
	start_color();
	init_pair(3, COLOR_BLUE, COLOR_BLUE);
	attron(COLOR_PAIR(3));
	//horizont
	for(int x = 0; x < windowWidth; x++)
		mvwprintw(stdscr, 0, x ,"#");
	for(int x = 0; x < windowWidth; x++)
		mvwprintw(stdscr, windowHeight - 1, x ,"#");
	// vertical
	for(int y = 0; y < windowHeight; y++)
		mvwprintw(stdscr, y, 0 ,"#");
	for(int y = 0; y < windowHeight; y++)
		mvwprintw(stdscr, y, windowWidth - 1 ,"#");
	attroff(COLOR_PAIR(3));
	move(0, 0);
}

void	Ncurses::printObject(Player &pl)
{
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, pl.getY() /*+ speed*/, pl.getX() ,	    "   /\\ ");
	mvwprintw(stdscr, pl.getY() + 1 /* + speed */, pl.getX() ,	"   \\#\\  ");
	mvwprintw(stdscr, pl.getY() + 2 /* + speed */, pl.getX() ,	"    \\#\\ ");
	mvwprintw(stdscr, pl.getY() + 3 /* + speed */, pl.getX() ,	"    /##\\ ");
	mvwprintw(stdscr, pl.getY() + 4 /* + speed */, pl.getX() ,	"   <===>\\ ");
	mvwprintw(stdscr, pl.getY() + 5 /* + speed */, pl.getX() ,	"   <####)> ");
	mvwprintw(stdscr, pl.getY() + 6 /* + speed */, pl.getX() ,	"   <===>/ ");
	mvwprintw(stdscr, pl.getY() + 7 /* + speed */, pl.getX() ,	"    \\##/ ");
	mvwprintw(stdscr, pl.getY() + 8 /* + speed */, pl.getX() ,	"    /#/ ");
	mvwprintw(stdscr, pl.getY() + 9 /* + speed */, pl.getX() ,	"   /#/ ");
	mvwprintw(stdscr, pl.getY() + 10/* + speed */, pl.getX() ,	"   \\/ ");
	bulletList *tmp = bList;

	attroff(COLOR_PAIR(1));
}

void	Ncurses::printObject(Enemy &obj)
{
	if (!obj.dead) {
		start_color();
		init_pair(2, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		mvwprintw(stdscr, obj.getY() + 1, obj.getX(), "        //-A-\\");
		mvwprintw(stdscr, obj.getY() + 2, obj.getX(), "  ___---=======---___");
		mvwprintw(stdscr, obj.getY() + 3, obj.getX(), "(=__\\###/.. ..\\###/__=)");
		mvwprintw(stdscr, obj.getY() + 4, obj.getX(), "     ---\\__O__/---");
		attroff(COLOR_PAIR(2));
	}
}


void	Ncurses::loop()
{
	int key;

	initscr();
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	key = 1;
	while (numLife)
	{
		if (!player.checkIfBottom() || checkBoom())
		{

			system("afplay Bomb.mp3 &");
			--numLife;
			clear();
			if (!numLife)
			{
				gameOver();
				refresh();
				sleep(3);
				clear();
				return ;
			} else
			{
				boom();
				refresh();
			}
			sleep(1);
			Ncurses();

		}
		clear();
		createNewEnemies();
		printObject(player);
		moveEnemies();
		//draw_frame();
		printBullets();
		moveBullets();
		checkIfBulletHitEnemy();
		chooseMove(key);
		printStat();
		refresh();
		key = getch();
		if (key == 32) {
			//std::cout << '\a';
			system("afplay shot.mp3 &");
			bList = bulletPushBack(bList, player);
		}
		if (key == 'q')
			exit(1);
	usleep(2000);
	}


}

void	Ncurses::chooseMove(int key)
{
		if (key == 65)
			player.moveUp(player);
		else if (key == 66)
			player.moveDown(player);
		else if (key == 67)
			player.moveRight(player);
		else if (key == 68)
			player.moveLeft(player);

}

void	Ncurses::chooseCoordinates()
{
	for (int i = 0; i < numEnemy; ++i)
	{
		enemy[i].setY(((float)windowHeight / numEnemy) * (i));

		enemy[i].setObjectView();
		enemy[i].moveAllCoords();
	}
}

void Ncurses::printBullets()
{
	bulletList *tmp;

	tmp = bList;
	curs_set(0);
	while (tmp)
	{
		if (static_cast<int>(tmp->bul->getX()) < windowWidth - 1)
			mvwprintw(stdscr, tmp->bul->getY() + 5 , tmp->bul->getX() + 10 ,	"*");
		tmp = tmp->next;
	}
}

void	Ncurses::moveBullets()
{
	bulletList *tmp;

	tmp = bList;
	while (tmp)
	{
		tmp->bul->moveRight(*tmp->bul);
		tmp = tmp->next;
	}
}

void	Ncurses::createNewEnemies()
{
	int r;


	//if (enemy)
	//	delete [] enemy;
	if (!enemy || !checkIfNew())
	{
		r = (int)random() % 4;
		r == 0 ? r = 1 : 0;
		enemy = new Enemy[r];
		numEnemy = r;
	}
	chooseCoordinates();
}

void	Ncurses::moveEnemies()
{

	int i;
	int r;

	i = 0;

		enemy[i].moveDown(enemy[i]);
	enemy[i].moveDown(enemy[i]);
	enemy[i].moveDown(enemy[i]);
	while (i < numEnemy)
	{
		r = (int)rand();
		if (r % 2 == 0)
			enemy[i].moveUp(enemy[i]);
		else
			enemy[i].moveDown(enemy[i]);
		enemy[i].moveLeft(enemy[i]);
		printObject(enemy[i]);
		++i;
	}
}

bool	Ncurses::checkBoom()
{
	int i;

	i = 0;
	while (i < numEnemy)
	{
		if (player == enemy[i])
			return (true);
		++i;
	}
	return (false);

}

bool	Ncurses::checkIfBulletHitEnemy()
{
	bulletList *tmp;
	int i ;
	int k;
		tmp = bList;
	while (tmp)
	{
		if (tmp->bul->arrPoint[0].x < windowWidth - 2)
		{
			i = 0;
			while (i < numEnemy) {
				k = 0;
				while (enemy[i].arrPoint[k].x != -99 && enemy[i].arrPoint[k].y != -99) {
					if (fabs(enemy[i].arrPoint[k].x - tmp->bul->arrPoint[0].x) < 0.2 && fabs(enemy[i].arrPoint[k].y - tmp->bul->arrPoint[0].y) < 0.2) {
						system("afplay Bomb.mp3 &");
						enemy[i].dead = true;
						enemy[i].setX(-99);
						enemy[i].setY(-99);
						tmp->bul->arrPoint[0].x = windowWidth + 20;
						tmp->bul->arrPoint[0].y = windowHeight+ 20;
						tmp->bul->setX(windowWidth + 20);
						tmp->bul->setY(windowWidth + 20);
						++score;
						return (true);
					}
					++k;
				}
				++i;
			}
		}
		tmp = tmp->next;
	}
	return (false);
}

bool	Ncurses::checkIfNew()
{
	int i;
	i = 0;

	while (i < numEnemy)
	{
		if (enemy[i].getX() > 0 + 2)
			return (true);
		++i;
	}
	return (false);


}

void	Ncurses::printStat()
{

	init_pair(4,COLOR_BLACK, COLOR_YELLOW);
	attron(COLOR_PAIR(4));
	int i;
	i = 0;
	mvwprintw(stdscr, windowHeight - 3 , 1,    "{GO UP - UP ARROW}{GO DOWN - DOWN ARROW}{GO RIGHT - RIGHT ARROW}{GO LEFT - LEFT ARROWW}{EXIT - Q}     NUMBER OF LIVES: %d TOTAL KILLS: %d ",numLife,score);
	attroff(COLOR_PAIR(4));
}

void	Ncurses::gameOver()
{
	init_pair(5,COLOR_BLACK, COLOR_RED);
	attron(COLOR_PAIR(5));
	mvwprintw(stdscr, windowHeight / 2 + 0 , windowWidth / 2 - 30, "  _______      ___      .___  ___.  _______               ______   ____    ____  _______ .______      ");
	mvwprintw(stdscr, windowHeight / 2 + 1 , windowWidth / 2 - 30, " /  _____|    /   \\     |   \\/   | |   ____|             /  __  \\  \\   \\  /   / |   ____||   _  \\     ");
	mvwprintw(stdscr, windowHeight / 2 + 2 , windowWidth / 2 - 30, "|  |  __     /  ^  \\    |  \\  /  | |  |__               |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    ");
	mvwprintw(stdscr, windowHeight / 2 + 3 , windowWidth / 2- 30, "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|              |  |  |  |   \\      /   |   __|  |      /     ");
	mvwprintw(stdscr, windowHeight / 2 + 4 , windowWidth / 2- 30 , "|  |__| |  /  _____  \\  |  |  |  | |  |____             |  `--'  |    \\    /    |  |____ |  |\\  \\----.");
	mvwprintw(stdscr, windowHeight / 2 + 5 , windowWidth / 2- 30 , " \\______| /__/     \\__\\ |__|  |__| |_______|             \\______/      \\__/     |_______|| _| `._____|");
	attroff(COLOR_PAIR(5));
}

void	Ncurses::boom()
{
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	attron(COLOR_PAIR(5));
	mvwprintw(stdscr, windowHeight / 2 + -10 /* + speed */, windowWidth / 2 - 20 , " |  _ \\   / _ \\   / _ \\  |  \\ /  |");
	mvwprintw(stdscr, windowHeight / 2 + -9 /* + speed */, windowWidth / 2 -20, " | |_) ) | | | | | | | | |   v   |");
	mvwprintw(stdscr, windowHeight / 2 + -8 /* + speed */, windowWidth / 2 -20, " |  _ (  | | | | | | | | | |\\_/| |");
	mvwprintw(stdscr, windowHeight / 2 + -7 /* + speed */, windowWidth / 2 -20, " | |_) ) | |_| | | |_| | | |   | |");
	mvwprintw(stdscr, windowHeight / 2 + -6 /* + speed */, windowWidth / 2 -20 , " |____/   \\___/   \\___/  |_|   |_|");
	attroff(COLOR_PAIR(5));
}
