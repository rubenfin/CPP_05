/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:31:59 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/03 14:32:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresedentialPardonForm",
	ppSignGrade, ppExecGrade), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy constructor called!" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

AForm	*PresidentialPardonForm::makeForm( AForm *form, std::string type, std::string target )
{
	if (form == NULL && type == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (form);
}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << "Informs that " << getTarget() << " has been pardoned by Zaphod Beeblebroxx" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}