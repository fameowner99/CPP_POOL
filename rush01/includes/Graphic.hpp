#ifndef GRAPHIC_HPP

#define GRAPHIC_HPP

#include "Point.hpp"
#include <vector>
#define	window_width 330
#define window_height 650

class Graphic
{
	private:
		unsigned int		vectorSize;
		std::vector<Point *> graph;
	public:
		unsigned int		getSize()const;
		Graphic();
		Graphic(const Graphic&);
		Graphic&operator=(const Graphic&);
		void	addPoint(float x, float y, float h);
		void	printAllPoints(Uint32 color, SDL_Surface *screen, float moveY);
		void	moveAllPoints();
		void	clearGraphic();
};

#endif