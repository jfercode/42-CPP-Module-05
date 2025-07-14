/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:26:27 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 13:34:39 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5, target) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	this->action();
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << this->getTarget()
			  << " has been pardoned by Zaphod Beeblebrox."	<< std::endl;
}
