/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:36:01 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 17:47:45 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137, target) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	this->action();
}

void	ShrubberyCreationForm::action(void) const
{
	std::ofstream out((getTarget() + "_shrubbery").c_str());
	if (!out)
	{	
		std::cerr << "Error: Could not create shrubbery file." << std::endl;
		return;
	}
	out << "	 |	" << std::endl;
	out << "   |||	" << std::endl;
	out << "  |||||	" << std::endl;
	out << " |||||||" << std::endl;
	out << "|||||||||" << std::endl;
	out << "   |||	" << std::endl;
	out << "   |||	" << std::endl;
	out.close();
}