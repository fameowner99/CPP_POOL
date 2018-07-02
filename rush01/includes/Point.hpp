#ifndef POINT_HPP

#define POINT_HPP

#include <SDL.h>

class Point
{
	public:
		Point();
		~Point();
		Point(const Point&);
		Point(const float x, const float y, const float h);
		Point &operator=(const Point&);
		void	drawPoint(Uint32 color, SDL_Surface *screen, float moveY);
		void	moveRight();
		float		getPosX()const;
		float	getPosY()const;
	private:
		float		posX;
		float		posY;
		float 		h;

};

#endif