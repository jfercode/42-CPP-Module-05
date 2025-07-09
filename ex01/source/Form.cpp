/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:14:19 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/09 19:46:43 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) 
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
	this->_isSigned = false;		
}

Form::~Form(void) { }

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getToExecute(void) const
{
	return (this->_gradeToExecute);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!\n");
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getToSign())
		throw (GradeTooLowException());
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form to sign grade " << f.getToSign()
	   << ", form grade to Execute " << f.getToExecute()
	   << ", form is signed " << f.getIsSigned() << std::endl;
	return (os);
}
