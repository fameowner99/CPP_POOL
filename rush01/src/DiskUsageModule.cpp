/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskUsageModule.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:26:52 by anesteru          #+#    #+#             */
/*   Updated: 2018/07/01 16:26:53 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiskUsageModule.hpp"

DiskUsageModule::DiskUsageModule(void) : _old_info(-1) {
	_name = "Disk usage";
}

DiskUsageModule::~DiskUsageModule(void) {

}

int			DiskUsageModule::info(std::string info)
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

std::string		DiskUsageModule::get_disk_usage(void) {

	char buffer[128];
	std::string result = "";
	FILE* pipe = popen("top -l 1 -n 0", "r");
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	result = result.substr(result.find("Disks: "));
	result = result.substr(0, result.find("\n"));
	this->_info = info(result);
	return result;
}

std::vector<std::string>			DiskUsageModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_disk_usage());
	return vec;
}
const char *DiskUsageModule::getName(void) const
{
	return (_name.c_str());
}

int 	DiskUsageModule::fgetInfo()
{
	if (this->_old_info == -1)
	{
		this->_old_info = this->_info;
		return 0;
	}
	int ret = this->_info - this->_old_info;
	this->_old_info = this->_info;
	return ret;
}
