/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 22:00:02 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/29 22:00:03 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameUsernameModule.hpp"
#include "DateTimeModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUInfoModule.hpp"
#include "RAMInfoModule.hpp"
#include "NetworkThroughputModule.hpp"
#include "DiskUsageModule.hpp"
#include "shellUI.hpp"
#include "Sdl.hpp"
#include "Point.hpp"
#include "Graphic.hpp"

int		main(int argc, char **argv)
{
	static_cast<void>(argc);
	if (argv[1] && !strcmp(argv[1], "-s"))
	{
		Sdl s;
		s.show();
	}
	else
	{
		shellUI sh;
		sh.show();
	}
	return 0;
}
