#include "Point.hpp"

Point::Point():posX(0), posY(0), h(0) {}

Point::~Point() {}

Point::Point(const Point &obj): h(0)
{
	*this = obj;
}
Point::Point(const float x, const float y, const float h): posX(x), posY(y), h(h)  {}

float Point::getPosY()const
{
	return (posY);
}

float Point::getPosX()const
{
	return (posX);
}

Point& Point::operator=(const Point &obj)
{
	posX = obj.getPosX();
	posY = obj.getPosY();
	return (*this);
}

void 	Point::moveRight()
{
	posX += 1;
}

void	Point::drawPoint(Uint32 color, SDL_Surface *screen, float moveY)
{
	SDL_Surface	*image;
	SDL_Rect	rect;
	image = SDL_CreateRGBSurface (0, 2, h, 32, 0, 0, 0, 0);
	SDL_FillRect(image, NULL, color);
	rect = image->clip_rect;
	rect.x = posX;
	rect.y = posY - moveY;
	SDL_BlitSurface(image, NULL, screen, &rect);
}