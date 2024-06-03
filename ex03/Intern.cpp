/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 18:14:45 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/03 14:47:29 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

AForm	*Intern::makeForm( std::string formName, std::string target )
{
	AForm	*form;

	form = AForm::makeForm(formName, target);
	if (!form)
		throw (Intern::FormNotFoundException());
	else
	{
		std::cout << YELLOW "Intern creates " << formName << RESET << std::endl;
		return (form);
	}
}

Intern::~Intern()
{
}

const char *Intern::FormNotFoundException::what(void) const noexcept
{
	return (RED "Form has not been found!" RESET);
}