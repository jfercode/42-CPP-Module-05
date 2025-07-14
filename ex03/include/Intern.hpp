/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:00:30 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 18:21:37 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		static AForm* createShrubbery(std::string const& target);
		static AForm* createRobotomy(std::string const& target);
		static AForm* createPresidential(std::string const& target);

	public:
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);
	
		AForm *makeForm(std::string const& formName, std::string const& target);
};

#endif 