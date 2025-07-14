/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:14:19 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 18:26:53 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target) 
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
	this->_isSigned = false;		
}

AForm::~AForm(void) { }

std::string	AForm::getName(void) const
{
	return (this->_name);
}

std::string AForm::getTarget(void) const
{
	return (this->_target);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getToExecute(void) const
{
	return (this->_gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("form grade too high!\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("form grade too low!\n");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("form not signed!\n");
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getToSign())
		throw (GradeTooLowException());
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", form to sign grade " << f.getToSign()
	   << ", form grade to Execute " << f.getToExecute()
	   << ", form is signed " << f.getIsSigned() 
	   << ", form target " << f.getTarget() << std::endl;
	return (os);
}

void	AForm::execute(Bureaucrat const & executor) const 
{
	if (!this->_isSigned)
		throw (FormNotSignedException());
	if (executor.getGrade() > this->_gradeToExecute)
		throw (GradeTooLowException());
	this->action();
}
