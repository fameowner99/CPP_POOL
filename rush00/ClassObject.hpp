#ifndef CLASSOBJECT_HPP

# define CLASSOBJECT_HPP

#include <string>
#include "unistd.h"
#include <sys/ioctl.h>
#include <iostream>
#include <cmath>
#include <ctime>

struct Point
{
	float x;
	float y;
};

class Object
{

	protected:
		char		**objectView;
		static const int 	moveLimit = 5;
		float 	x;
		float 	y;
		int 	healthPoints;
		int 	maxHealthPoints;
		int		windowWidth;
		int		windowHeight;
		Point	*convertViewToCoordinates();




	public:
		Point	*arrPoint;
		Object();
		virtual ~Object();
		Object(const Object&);
		Object&operator=(const Object&);
		void 	setX(const float&);
		float		getX()const;
		void 	setY(const float&);
		float		getY()const;
		//char	**getObjectView();
};


/*
# define RED "\033[0;31m"
# define BRED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BGREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BYELLOW "\033[01;33m"
# define BLUE "\033[0;34m"
# define BBLUE "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define BMAGENTA "\033[1;35m"
# define CYAN "\033[0;36m"
# define BCYAN "\033[1;36m"
# define RESET "\033[0m"
 */
#endif