/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfoModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:08:13 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 20:08:14 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMInfoModule.hpp"

RAMInfoModule::RAMInfoModule(void)
{
	_name = "RAM info";
}

RAMInfoModule::~RAMInfoModule(void) {

}

int RAMInfoModule::info(std::string info)
{
	std::stringstream s(info);
	int ret;
	char ch;

	while (!(s >> ret))
	{
		s.clear();
		s >> ch;
	}
	return (ret);
}

std::string		RAMInfoModule::get_ram_info(void) {

	char buffer[128];
	std::string result = "";
	FILE* pipe = popen("top -l 1 -n 0", "r");
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	result = result.substr(result.find("PhysMem: "));
	result = result.substr(0, result.find("\nVM: "));
	this->_info = info(result);
	return result;
}

std::vector<std::string>			RAMInfoModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_ram_info());
	return vec;
}
const char *RAMInfoModule::getName(void) const
{
	return (_name.c_str());
}

int RAMInfoModule::fgetInfo()
{
	return this->_info;
}