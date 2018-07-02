/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 22:09:30 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/29 22:09:31 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{

public:

	IMonitorDisplay(void);
	virtual ~IMonitorDisplay(void);
	virtual void show() = 0;
	
private:

	IMonitorDisplay(IMonitorDisplay const &src);

	IMonitorDisplay		&operator=(IMonitorDisplay const &rhs);

};

#endif
