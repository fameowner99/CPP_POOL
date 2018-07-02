#include "replace.hpp"
#include <fstream>
#include <iostream>

static const std::string nameOfNewFile(std::string filename)
{
	int i;

	i = 0;
	while (filename[i])
	{
		filename[i] = static_cast<char>(toupper(filename[i]));
		++i;
	}
	return (filename + ".replace");
}

void	ft_replace(const std::string filename, const std::string str1, const std::string str2)
{
	long long int	length;
	std::ifstream	file(filename);
	char			*buf;

	if (!file.is_open())
	{
		std::cout << "Wrong file!" << std::endl;
		return;
	}
	std::ofstream fout(nameOfNewFile(filename), std::ios_base::trunc | std::ios_base::out);
	file.seekg(0, std::ios::end);
	length = file.tellg();
	buf = new char [length];
	file.seekg(0, std::ios::beg);
	file.read(buf, length);
	std::string str(buf);
	delete[] buf;
	while (str.find(str1) != std::string::npos)
		str.replace(str.find(str1), str1.length(), str2);
	fout << str;
	file.close();
	fout.close();
}