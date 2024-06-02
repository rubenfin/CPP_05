/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 18:14:45 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 18:38:15 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string levels[] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};
	AForm *classes[]{
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target),
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == levels[i])
			return (std::cout << "Intern creates " << classes[i]->getName() << std::endl, classes[i]);
	}
	return (nullptr);
}

Intern::~Intern()
{
}