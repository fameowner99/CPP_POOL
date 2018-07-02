#ifndef LOGGER_HPP

# define LOGGER_HPP

#include <string>

class Logger
{
	private:
		void 				logToConsole(const std::string &message);
		void				logToFile(const std::string &message);
		const std::string	makeLogEntry(const std::string &simpleMessage)const;
		std::string			fileName;
	public:
		void				log(std::string const &dest, std::string const &message);
		Logger(const std::string &newFileName);
		Logger();

};

#endif