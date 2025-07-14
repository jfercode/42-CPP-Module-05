/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:13:00 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 17:28:28 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
	
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;
		void	action(void) const;
};

# endif 