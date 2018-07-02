/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphicalUI.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 22:26:23 by anesteru          #+#    #+#             */
/*   Updated: 2018/06/29 22:26:24 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALUI_HPP
# define GRAPHICALUI_HPP

# include "IMonitorDisplay.hpp"

class graphicalUI : public IMonitorDisplay
{

public:

	graphicalUI(void);
	~graphicalUI(void);


private:

	graphicalUI(graphicalUI const &src);
	
	graphicalUI		&operator=(graphicalUI const &rhs);
};

#endif

