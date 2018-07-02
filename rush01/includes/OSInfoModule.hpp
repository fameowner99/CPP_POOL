/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:32:30 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:32:31 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include "IMonitorModule.hpp"

class OSInfoModule : public IMonitorModule
{

public:

	OSInfoModule(void);
	~OSInfoModule(void);

	std::string		get_macOS_version(void);
	std::string		get_kernel_info(void);
	std::string		get_kernel_date(void);
	std::vector<std::string>			getInfo();
	const char *getName(void) const;

private:

	OSInfoModule(OSInfoModule const &src);

	OSInfoModule		&operator=(OSInfoModule const &rhs);
};

#endif
