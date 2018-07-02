/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:44:05 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:44:07 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

# include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule
{

public:

	DateTimeModule(void);
	~DateTimeModule(void);

	std::string		get_date(void);
	std::string		get_time(void);
	std::vector<std::string>			getInfo();
	const char *getName(void) const;
private:

	DateTimeModule(DateTimeModule const &src);

	DateTimeModule		&operator=(DateTimeModule const &rhs);
};

#endif
