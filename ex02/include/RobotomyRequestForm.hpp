/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:15:17 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 14:02:15 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>


class RobotomyRequestForm : public AForm
{
	private:
		
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm(void);

		void execute(Bureaucrat const & executor) const;
		void action(void) const;
};

#endif