#include "Logger.hpp"
#include <ctime>
#include <iostream>
#include <fstream>

const std::string	Logger::makeLogEntry(const std::string &simpleMessage) const
{
	std::time_t t = std::time(NULL); // get time now
	struct tm	*timeinfo;
	char		buf[50];

	time(&t);
	timeinfo = localtime(&t);
	strftime(buf, sizeof(buf),"%d-%m-%Y %I:%M:%S", timeinfo );
	std::string str(buf);
	return  ("[" + str + "]" + "<" + simpleMessage + ">" + "\n");
}

void				Logger::logToConsole(const std::string &message)
{
	std::cout << makeLogEntry(message);
}

void				Logger::logToFile(const std::string &message)
{
	std::ofstream	fout(fileName, std::ios_base::out | std::ios_base::app);
	fout << makeLogEntry(message);
	fout.close();
}

Logger::Logger()
{
	fileName = "test.txt";
}

Logger::Logger(const std::string &newFileName): fileName(newFileName){}

void				Logger::log(std::string const &dest, std::string const &message)
{
	void (Logger::*chooseDest[2])(const std::string &message) = {&Logger::logToConsole, &Logger::logToFile};
	std::string arr[2] = {"logToConsole", "logToFile"};

	for(int i = 0; i < 2; ++i)
	{
		if (arr[i] == dest)
		{
			(this->*chooseDest[i])(message);
		}
	}
}