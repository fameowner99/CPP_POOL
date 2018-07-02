#include "Graphic.hpp"

Graphic::Graphic():vectorSize(0) {}

Graphic::Graphic(const Graphic &obj):vectorSize(0)
{
	*this = obj;
}

unsigned int Graphic::getSize()const
{
	return (vectorSize);
}

Graphic& Graphic::operator=(const Graphic &obj)
{
	vectorSize = obj.getSize();
	graph = obj.graph;
	return (*this);
}

void	Graphic::addPoint(float x, float y, float h)
{
	graph.push_back(new Point(x, y, h));
	++vectorSize;
}

void	Graphic::printAllPoints(Uint32 color, SDL_Surface *screen, float moveY)
{
	for (unsigned int i = 0; i < vectorSize; ++i)
	{
		graph[i]->drawPoint(color, screen, moveY);
	}
}

void	Graphic::clearGraphic()
{
	std::vector<Point*>::iterator it;
 	for ( it = graph.begin(); it != graph.end(); )
		if( (*it)->getPosX() > window_width ){
			delete *it;
	it = graph.erase(it);
			--vectorSize;
}
else {
++it;
}
}



void	Graphic::moveAllPoints()
{
	clearGraphic();
	for (unsigned int i = 0; i < vectorSize; ++i)
	{
		graph[i]->moveRight();
	}
}