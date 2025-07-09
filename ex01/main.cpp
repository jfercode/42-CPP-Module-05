/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:10:38 by jaferna2          #+#    #+#             */
/*   Updated: 2025/07/09 19:47:24 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main() 
{
    try 
	{
        Bureaucrat bob("Bob", 50);
        Form taxForm("TaxForm", 100, 100);

        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat karen("Karen", 120);
        Form secretForm("SecretForm", 100, 100);

        std::cout << secretForm << std::endl;
        karen.signForm(secretForm);
        std::cout << secretForm << std::endl;

    }
	catch (std::exception &e) 
	{
        std::cerr << "Caught error in main: " << e.what() << std::endl;
    }
    return (0);
}

