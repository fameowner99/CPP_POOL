/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 22:08:42 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/29 22:08:43 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "gkrellm.hpp"
# include <vector>
# include <string>
# include <sstream>

class IMonitorModule
{

public:

	IMonitorModule(void);
	virtual ~IMonitorModule(void);
	virtual std::vector<std::string> getInfo(void) = 0;
	virtual const char *getName(void) const = 0;

protected:
	std::string _name;
private:
	IMonitorModule(IMonitorModule const &src);

	IMonitorModule		&operator=(IMonitorModule const &rhs);
};

#endif
