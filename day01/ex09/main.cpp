#include "Logger.hpp"

int		main()
{
	Logger l("abc");

	l.log("logToConsole", "kek");
	l.log("logToFile","sada");
	return (0);
}