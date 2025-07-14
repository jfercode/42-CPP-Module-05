/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:06:58 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 17:40:57 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	const std::string	_target;
public:
	AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
	virtual ~AForm(void);
	
	std::string	getName(void) const;
	std::string getTarget(void) const;
	bool getIsSigned(void) const;
	int getToSign(void) const;
	int getToExecute(void) const;
	
	class GradeTooHighException : public std::exception {
		const char *what() const throw();	
	};
	
	class GradeTooLowException : public std::exception {
		const char *what() const throw();	
	};
	
	class FormNotSignedException : public std::exception {
		const char *what() const throw();
	};
	
	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const & executor) const;
	virtual void action() const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif