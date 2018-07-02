/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellUI.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 22:33:29 by anesteru          #+#    #+#             */
/*   Updated: 2018/07/01 16:48:25 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellUI.hpp"

shellUI::shellUI(void) {
	init();
}

shellUI::~shellUI(void) {
    endwin();
    curs_set(true);
}

unsigned int    shellUI::time_diff(timeval t1, timeval t2) 
{
    return ((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void shellUI::rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1 - 1, x1, 0, x2-x1);
    mvvline(y1, x1 - 1, 0, y2-y1 + 2);
    mvvline(y1, x2, 0, y2-y1 + 2);
}

void shellUI::print_box(const int boxy, const int boxheight,
	const int boxbeg, const std::string &boxname)
{
	rectangle(boxy, boxbeg, boxy + boxheight, boxbeg + BOXSIZE);
	attron(COLOR_PAIR(1));
	mvprintw(boxy, boxbeg + ((BOXSIZE - boxname.size()) / 2), boxname.c_str());
	attroff(COLOR_PAIR(1));
}


void shellUI::printScreen(void)
{
	int boxbeg;
	unsigned int i = 0;
	unsigned int j;
	int fieldtop = 4;
	std::vector<std::string> fields;
	IMonitorModule *modules[] = 
		{&hum, &dtm, &osm, &cim, &rim, &ntm, &dum};
 
 	getmaxyx( stdscr, winy, winx );
	if (winx < BOXSIZE)
		boxbeg = 0;
	else
		boxbeg = (winx - BOXSIZE) / 2;

    mvaddch(fieldtop - 1, boxbeg + BOXSIZE, ACS_URCORNER);
    mvaddch(fieldtop - 1, boxbeg - 1, ACS_ULCORNER);
	while (i < sizeof(modules) / sizeof(modules[0]))
	{
		fields = modules[i]->getInfo();
		print_box(fieldtop, fields.size() + 1, boxbeg, modules[i]->getName());
		j = 0;
		while (j < fields.size())
		{
			++fieldtop;
			mvprintw(fieldtop, boxbeg + (BOXSIZE - fields[j].size()) / 2, fields[j].c_str());
			++j;
		}
		fieldtop += 3;
		++i;
	}
    mvhline(fieldtop, boxbeg, 0, BOXSIZE);
    mvaddch(fieldtop, boxbeg - 1, ACS_LLCORNER);
    mvaddch(fieldtop, boxbeg + BOXSIZE, ACS_LRCORNER);
}

void shellUI::init(void)
{
	initscr();
	keypad(stdscr, true);
	noecho();
    timeout(0);
    cbreak();
    gettimeofday(&start, NULL);
    curs_set(false);
    refresh();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    printScreen();
   	
}

void shellUI::show(void)
{
	int input;
	input = getch();
	while (1)
    {	
    	gettimeofday(&now, NULL);
    	input = getch();  
    	if (input == 27)
    		break ;
    	if (time_diff(start, now) >= 900000) 
    	{
    		clear();
			printScreen();

			refresh();

			start = now;
		}
	}
}

int shellUI::winx = 0;
int shellUI::winy = 0;

