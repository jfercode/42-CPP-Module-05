/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:36:14 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 17:24:28 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45, target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	this->action();
}

void RobotomyRequestForm::action(void) const
{
	std::cout << "BZZZZZZzzzzzz... drilling noises..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget()
			<< " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on "
			<< this->getTarget() << "." << std::endl;
}
