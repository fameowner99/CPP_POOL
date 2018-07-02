/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:32:48 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:32:49 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(void)
{
	_name = "OS info";
}

OSInfoModule::~OSInfoModule(void) {

}

std::string		OSInfoModule::get_macOS_version(void) {

	char buffer[128];
	std::string result = "";
	FILE* pipe = popen("sw_vers -productVersion", "r");
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	result = result.substr(0, result.length() - 1);
	if (result.substr(0, 5) == "10.12")
		result += " Sierra";
	else if (result.substr(0, 5) == "10.13")
		result += " High Sierra";
	else if (result.substr(0, 5) == "10.14")
		result += " Mojave";
	return "macOS " + result;
}

std::string		OSInfoModule::get_kernel_info(void) {

	struct utsname uts;
	uname(&uts);
	uts.version[28] = 0;
	return std::string(uts.version);
}

std::string		OSInfoModule::get_kernel_date(void) {

	struct utsname uts;
	uname(&uts);
	uts.version[58] = 0;
	return std::string(uts.version + 30);
}

std::vector<std::string>			OSInfoModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_macOS_version());
	vec.push_back(get_kernel_info());
	vec.push_back(get_kernel_date());
	return vec;
}

const char *OSInfoModule::getName(void) const
{
	return (_name.c_str());
}