/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:35:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 18:12:55 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat Jack = Bureaucrat("Jack", 1, 4);
        PresidentialPardonForm pres = PresidentialPardonForm("Mozambique");
    
        pres.beSigned(Jack);    
        pres.execute(Jack);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    
    try
    {
        Bureaucrat Jack = Bureaucrat("Jack", 1, 4);
        RobotomyRequestForm pres = RobotomyRequestForm("Mozambique");
    
        pres.beSigned(Jack);    
        pres.execute(Jack);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    
    try
    {
        Bureaucrat Jack = Bureaucrat("Jack", 1, 150);
        ShrubberyCreationForm pres = ShrubberyCreationForm("Mozambique");
    
        pres.beSigned(Jack);    
        pres.execute(Jack);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
