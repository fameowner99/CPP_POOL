/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameUsernameModule.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:22:48 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:22:50 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameUsernameModule.hpp"

HostnameUsernameModule::HostnameUsernameModule(void)
{
	_name = "Hostname/username";
}

HostnameUsernameModule::~HostnameUsernameModule(void) {

}

std::string		HostnameUsernameModule::get_hostname(void) {

	char hostname[128];
	gethostname(hostname, 128);

	return std::string(hostname);
}

std::string		HostnameUsernameModule::get_username(void) {

	char username[128];
	getlogin_r(username, 128);

	return std::string(username);
}

std::vector<std::string>			HostnameUsernameModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_hostname());
	vec.push_back(get_username());
	return vec;
}
const char *HostnameUsernameModule::getName(void) const
{
	return (_name.c_str());
}