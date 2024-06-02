/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:10 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 18:12:34 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm",
	scSignGrade, scExecGrade), _target(target)
{
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::executeForm(void) const
{
	std::string command = "tree > " + this->getTarget() + "_shrubbery";
    const char *cmd = command.c_str();
    system(cmd);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}