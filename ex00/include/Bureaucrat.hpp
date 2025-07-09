/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:19:41 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/09 16:34:00 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat 
{
private:
	const std::string 	_name;
	int					_grade;
	void	GradeTooHighException(void);
	void	GradeTooLowException(void);
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	
	const std::string	getName(void) const;
	const int			getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
};


#endif