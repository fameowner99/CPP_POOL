/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfoModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:08:29 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 20:08:30 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMINFOMODULE_HPP
# define RAMINFOMODULE_HPP

# include "IMonitorModule.hpp"

class RAMInfoModule : public IMonitorModule
{

public:

	RAMInfoModule(void);
	~RAMInfoModule(void);

	std::string					get_ram_info(void);
	std::vector<std::string>	getInfo();
	const char 					*getName(void) const;
	int 						fgetInfo();
	int 						info(std::string info);
private:

	RAMInfoModule(RAMInfoModule const &src);

	RAMInfoModule		&operator=(RAMInfoModule const &rhs);

	int					_info;
};

#endif
