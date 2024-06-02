/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:31:59 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 16:37:47 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresedentialPardonForm",
	ppSignGrade, ppExecGrade), _target(target)
{
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::executeForm(void) const
{
    std::cout << "Informs that " << getTarget() << " has been pardoned by Zaphod Beeblebroxx" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}