/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:06:58 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/09 19:53:59 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form(void);
	std::string	getName(void) const;
	bool getIsSigned(void) const;
	int getToSign(void) const;
	int getToExecute(void) const;
	
	class GradeTooHighException : public std::exception {
		const char *what() const throw();	
	};
	
	class GradeTooLowException : public std::exception {
		const char *what() const throw();	
	};
	
	void beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif