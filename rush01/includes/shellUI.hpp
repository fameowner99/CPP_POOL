/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellUI.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 22:26:02 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/29 22:26:03 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLUI_HPP
# define SHELLUI_HPP

# include "IMonitorDisplay.hpp"
#include <sys/time.h>
#include <ncurses.h>
#include "HostnameUsernameModule.hpp"
#include "DateTimeModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUInfoModule.hpp"
#include "RAMInfoModule.hpp"
#include "NetworkThroughputModule.hpp"
#include "DiskUsageModule.hpp"
#include <cstdlib>
#define BOXSIZE 66

class shellUI : public IMonitorDisplay
{

public:

	shellUI(void);
	~shellUI(void);

	void	show(void);

private:

	void init(void);
	void printScreen(void);
	unsigned int time_diff(timeval t1, timeval t2);
	void rectangle(int, int, int, int);
	void print_box(const int boxy, const int boxheight,
		const int boxbegin, const std::string &boxname);

	static int winx;
	static int winy;

	HostnameUsernameModule		hum;
	DateTimeModule				dtm;
	OSInfoModule				osm;
	CPUInfoModule				cim;
	RAMInfoModule				rim;
	NetworkThroughputModule		ntm;
	DiskUsageModule				dum;

	struct timeval	now;
	unsigned long	timeFrame;
	struct timeval	start;

	shellUI(shellUI const &src);

	shellUI		&operator=(shellUI const &rhs);
};

#endif
