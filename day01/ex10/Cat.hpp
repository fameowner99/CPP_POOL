#ifndef CAT_HPP

# define CAT_HPP

#include <iostream>
#include <sys/stat.h>
#include <fstream>

class Cat
{
	private:
		int		argc;
		char**	argv;
		void 	standartInput();
		bool 	validFile(std::string &fileName);
		bool	access(std::string &fileName);
		bool 	isDir(std::string &fileName);
		void 	messageAccess(std::string &fileName);
		void 	messageValidFile(std::string &fileName);
		void 	messageIsDir(std::string &fileName);
		struct stat getStat(std::string &fileName);
		void	printFile(std::string &fileName);

		void	resolve();

	public:
		Cat(int newArgc, char **newArgv);


};

#endif