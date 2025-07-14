/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:10:38 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 18:25:05 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/Intern.hpp"

int main()
{
    Intern someRandomIntern;

    std::cout << "\n✅ Probando formularios válidos:" << std::endl;

    AForm *form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form1)
    {
        std::cout << *form1 << std::endl;
        delete form1;
    }

    AForm *form2 = someRandomIntern.makeForm("shrubbery creation", "Backyard");
    if (form2)
    {
        std::cout << *form2 << std::endl;
        delete form2;
    }

    AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (form3)
    {
        std::cout << *form3 << std::endl;
        delete form3;
    }

    std::cout << "\n❌ Probando formulario inválido:" << std::endl;

    AForm *form4 = someRandomIntern.makeForm("coffee making", "Intern");
    if (!form4)
        std::cout << "No se ha creado ningún formulario." << std::endl;

    return (0);
}
