/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:43:52 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:43:53 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule(void)
{
	_name = "Date/time";
}

DateTimeModule::~DateTimeModule(void) {

}

std::string		DateTimeModule::get_date(void) {

	std::time_t	t = std::time(0);
	std::tm		*now = std::localtime(&t);
	std::string wd[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	std::string month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	return std::string((wd[now->tm_wday] + " " + std::to_string(now->tm_mday) + " " + month[now->tm_mon]));
}

std::string		DateTimeModule::get_time(void) {

	std::time_t t = std::time(0);
	char buf[128];
	struct tm  tstruct = *localtime(&t);
	std::strftime(buf, sizeof(buf), "%X", &tstruct);
	return std::string(buf);
}

std::vector<std::string>			DateTimeModule::getInfo()
{
	std::vector<std::string> vec;
	vec.push_back(this->get_date());
	vec.push_back(this->get_time());
	return vec;
}
const char *DateTimeModule::getName(void) const
{
	return (_name.c_str());
}