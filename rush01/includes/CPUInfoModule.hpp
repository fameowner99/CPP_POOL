/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfoModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:58:13 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 17:58:14 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "IMonitorModule.hpp"
# include <sstream>

class CPUInfoModule : public IMonitorModule
{

public:

	CPUInfoModule(void);
	~CPUInfoModule(void);
	const char *getName(void) const;
	std::vector<std::string>	getInfo();
	std::string					get_cpu_info(void);
	std::string					get_cpu_load(void);
	float 						info(std::string info);
	float 						fgetInfo();
private:

	CPUInfoModule(CPUInfoModule const &src);

	CPUInfoModule		&operator=(CPUInfoModule const &rhs);
	float				_info;
};

#endif
