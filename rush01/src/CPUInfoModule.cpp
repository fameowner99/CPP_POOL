/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfoModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:58:04 by anesteru          #+#    #+#             */
/*   Updated: 2018/07/01 12:09:19 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUInfoModule.hpp"

CPUInfoModule::CPUInfoModule(void)
{
	_name = "CPU info";
}

CPUInfoModule::~CPUInfoModule(void) {

}

float CPUInfoModule::info(std::string info)
{
	std::stringstream s(info);
	float ret;
	char ch;

	while (!(s >> ret))
	{
		s.clear();
		s >> ch;
	}
	return (ret);
}

std::string		CPUInfoModule::get_cpu_load(void) {

	char buffer[128];
	size_t firstprocent = 0;
	std::string result = "";
	FILE* pipe = popen("top -l 1 -n 0", "r");
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	result = result.substr(result.find("CPU usage: "));
	result = result.substr(0, result.find("\nSharedLibs: "));
	while (1)
	{
		firstprocent = result.find_first_of("%", firstprocent);
		if (firstprocent == std::string::npos)
			break;
		result.replace(firstprocent, 1, "%%");
		firstprocent += 2;
	}
	while (result.size() < 51)
		result += " ";
	this->_info = info(result);
	return result;
}

std::string		CPUInfoModule::get_cpu_info(void) {

	char buffer[128];
	size_t bufferlen = 128;
	sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);
	unsigned int num = std::thread::hardware_concurrency();
	return std::string(buffer + std::string(" " + std::to_string(num) + " cores"));
}

std::vector<std::string>			CPUInfoModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_cpu_load());
	vec.push_back(get_cpu_info());
	return vec;
}

const char *CPUInfoModule::getName(void) const
{
	return (_name.c_str());
}

float 		CPUInfoModule::fgetInfo(void) {

	return this->_info;
}
