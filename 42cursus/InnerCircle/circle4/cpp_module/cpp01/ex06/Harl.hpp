/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:36:36 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 20:55:10 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
 public:
	Harl(void);
	~Harl();
	void complain(std::string level);
};

#endif
