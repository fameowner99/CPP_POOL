/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThroughputModule.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:09:10 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 20:09:11 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkThroughputModule.hpp"

NetworkThroughputModule::NetworkThroughputModule(void) : _old_info(-1) {
	_name = "Network throughput info";
}

NetworkThroughputModule::~NetworkThroughputModule(void) {

}

int 	NetworkThroughputModule::info(std::string info)
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


std::string		NetworkThroughputModule::get_network_throughput(void) {

	char buffer[128];
	std::string result = "";
	FILE* pipe = popen("top -l 1 -n 0", "r");
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	result = result.substr(result.find("packets: "));
	result = result.substr(0, result.find("\nDisks: "));
	this->_info = info(result);
	return result;
}

std::vector<std::string>			NetworkThroughputModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_network_throughput());
	return vec;
}
const char *NetworkThroughputModule::getName(void) const
{
	return (_name.c_str());
}

int 	NetworkThroughputModule::fgetInfo()
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
