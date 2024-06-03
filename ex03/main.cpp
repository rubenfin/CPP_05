/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:35:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/03 14:45:02 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	AForm	*form;
	Intern	Newbie;
	
	form = NULL;
	std::cout << PINK "\n--Create all types of forms and form with incorrect type--" RESET << std::endl;
	{
		try
		{
			form = Newbie.makeForm("presidential pardon", "Adam");
			delete form;
			form = Newbie.makeForm("robotomy request", "Ben");
			delete form;
			form = Newbie.makeForm("shrubbery creation", "Homie");
			delete form;
			form = Newbie.makeForm("invalid form", "Wrong");
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << PINK "\n-----form functionality test-----" RESET << std::endl;
	Bureaucrat	Bob("Bob", 100, 5);
	
	form = Newbie.makeForm("shrubbery creation", "Bender");
	// std::cout << *form << std::endl;
	form->beSigned(Bob);
	form->execute(Bob);
	// std::cout << *form << std::endl;
	delete form;
	return (0);
}
