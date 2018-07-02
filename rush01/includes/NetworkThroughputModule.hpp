/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThroughputModule.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:09:29 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/30 20:09:30 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKTHROUGHPUTMODULE_HPP
# define NETWORKTHROUGHPUTMODULE_HPP

# include "IMonitorModule.hpp"

class NetworkThroughputModule : public IMonitorModule
{

public:

	NetworkThroughputModule(void);
	~NetworkThroughputModule(void);

	std::string					get_network_throughput(void);
	std::vector<std::string>	getInfo();
	const char					*getName(void) const;
	int 						fgetInfo();
	int							info(std::string info);

private:

	NetworkThroughputModule(NetworkThroughputModule const &src);

	NetworkThroughputModule		&operator=(NetworkThroughputModule const &rhs);

	int				_info;
	int				_old_info;
};

#endif
