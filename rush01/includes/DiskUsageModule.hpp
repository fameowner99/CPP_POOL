/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskUsageModule.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:27:02 by anesteru          #+#    #+#             */
/*   Updated: 2018/07/01 16:27:03 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKUSAGEMODULE_HPP
# define DISKUSAGEMODULE_HPP

# include "IMonitorModule.hpp"

class DiskUsageModule : public IMonitorModule
{

public:

	DiskUsageModule(void);
	~DiskUsageModule(void);

	std::string					get_disk_usage(void);
	std::vector<std::string>	getInfo();
	const char 					*getName(void) const;
	int 						fgetInfo();
	int							info(std::string info);
private:

	DiskUsageModule(DiskUsageModule const &src);

	DiskUsageModule		&operator=(DiskUsageModule const &rhs);

	int				_info;
	int				_old_info;
};

#endif
