#include "Cat.hpp"

Cat::Cat(int newArgc, char **newArgv):argc(newArgc), argv(newArgv)
{
	resolve();
}

void 	Cat::messageAccess(std::string &fileName)
{
	std::cout << "cato9tails: " << fileName << ": Permission denied" << std::endl;
}

void	Cat::messageIsDir(std::string &fileName)
{
	std::cout << "cato9tails: " << fileName << " Is a directory" << std::endl;
}

void	Cat::messageValidFile(std::string &fileName)
{
	std::cout << "cato9tails: " << fileName << " No such file or directory" << std::endl;
}

bool	Cat::access(std::string &fileName)
{
	struct stat	s;

	s = getStat(fileName);
	return (static_cast<bool>(s.st_mode & S_IRUSR));
}

bool	Cat::isDir(std::string &fileName)
{
	struct stat	s;

	s = getStat(fileName);
	return (!S_ISDIR(s.st_mode));

}

bool	Cat::validFile(std::string &fileName)
{
	struct stat results;
	int	r;

	r = stat(fileName.c_str(), &results);

	if (r == -1)
		return (false);
	return (true);
}

struct stat Cat::getStat(std::string &fileName)
{
	struct stat results;

	stat(fileName.c_str(), &results);
	return (results);
}

void	Cat::printFile(std::string &fileName)
{
	std::ifstream  readFile(fileName);

	if (!readFile.is_open())
		return ;
	std::cout << readFile.rdbuf();

}

void	Cat::standartInput()
{
	for (std::string line; std::getline(std::cin, line);)
	{
		std::cout << line << std::endl;
	}
}

void 	Cat::resolve()
{
	if (argc == 1)
		standartInput();
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string s(argv[i]);
			if (!validFile(s))
				messageValidFile(s);
			else if (!access(s))
				messageAccess(s);
			else if (!isDir(s))
				messageIsDir(s);
			else
				printFile(s);
		}
	}
}