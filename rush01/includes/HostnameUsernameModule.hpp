/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameUsernameModule.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:22:31 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:22:32 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEUSERNAMEMODULE_HPP
# define HOSTNAMEUSERNAMEMODULE_HPP

# include "IMonitorModule.hpp"

class HostnameUsernameModule : public IMonitorModule
{

public:

	HostnameUsernameModule(void);
	~HostnameUsernameModule(void);

	std::string		get_hostname(void);
	std::string		get_username(void);
	std::vector<std::string>			getInfo();
	const char *getName(void) const;
private:

	HostnameUsernameModule(HostnameUsernameModule const &src);

	HostnameUsernameModule		&operator=(HostnameUsernameModule const &rhs);
};

#endif

