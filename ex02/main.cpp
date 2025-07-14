/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:10:38 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/14 17:46:37 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);
        Bureaucrat carl("Carl", 150);

        AForm *shrub = new ShrubberyCreationForm("garden");
        AForm *robo = new RobotomyRequestForm("Bender");
        AForm *pres = new PresidentialPardonForm("Ford");

        // ---- CASO 1: Intento de ejecutar sin firmar ----
        try
        {
            shrub->execute(alice); // debería fallar
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 1] " << e.what() << std::endl;
        }

        // ---- CASO 2: Carl intenta firmar (debería fallar) ----
        try
        {
            carl.signForm(*shrub);
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 2] " << e.what() << std::endl;
        }

        // ---- CASO 3: Bob firma Shrubbery (éxito), pero no puede ejecutarlo ----
        try
        {
            bob.signForm(*shrub);
            bob.executeForm(*shrub); // debe fallar por permisos
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 3] " << e.what() << std::endl;
        }

        // ---- CASO 4: Alice firma y ejecuta los 3 formularios ----
        try
        {
            alice.signForm(*robo);
            alice.signForm(*pres);
            alice.executeForm(*robo);
            alice.executeForm(*pres);
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 4] " << e.what() << std::endl;
        }

        // ---- CASO 5: Alice también ejecuta Shrubbery que firmó Bob ----
        try
        {
            alice.executeForm(*shrub); // debe tener éxito
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 5] " << e.what() << std::endl;
        }
        delete shrub;
        delete robo;
        delete pres;
    }
    catch (const std::exception &e)
    {
        std::cerr << "[FATAL ERROR] " << e.what() << std::endl;
    }
}
