/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:10 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/03 12:51:20 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm",
	scSignGrade, scExecGrade), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy constructor called!" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
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