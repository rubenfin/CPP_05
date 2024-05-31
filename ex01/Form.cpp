/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:37:02 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/31 17:16:11 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

Form::~Form()
{
}

const std::string Form::getName(void)
{
	return (this->_name);
}
bool Form::getSigned(void)
{
	return (this->_isSigned);
}
int Form::getSignGrade(void)
{
	return (this->_signGrade);
}
int Form::getExecuteGrade(void)
{
	return (this->_executeGrade);
}

std::ostream &operator<<(std::ostream &os, Form obj)
{
	os << "Form " << obj.getName() << "has sign grade " << obj.getSignGrade();
	os << " and execute grade " << obj.getExecuteGrade() << " and is ";
	obj.getSigned() ? os << GREEN "signed " RESET  : os << RED "not signed " RESET;
	return (os);
}
