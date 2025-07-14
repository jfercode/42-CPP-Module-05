/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:04:54 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 18:25:49 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern(void) { }

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);	
}

Intern::~Intern(void) { }

AForm	*Intern::makeForm(std::string const& formName, std::string const& target)
{
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon" };
	AForm *(*funcs[])(std::string const&) = { &createShrubbery, &createRobotomy, &createPresidential };
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			AForm *form = funcs[i](target);
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
	}
	std::cerr << "Intern: unknown form name \"" << formName << "\"" << std::endl;
	return (NULL);
}

AForm* Intern::createShrubbery(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}
