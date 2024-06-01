/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:37:02 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/01 14:14:28 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

Form::Form(const std::string &name, int signGrade) : _name(name),
	_isSigned(false), _signGrade(signGrade), _executeGrade(1)
{
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
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

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (!bureaucrat.signForm(*this))
			return ;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his/her grade is too low!" << std::endl;
		return ;
	}
	this->_isSigned = true;
}
const char *Form::GradeTooHighException::what(void) const noexcept
{
	return (RED "Form grade is too High!" RESET);
}

const char *Form::GradeTooLowException::what(void) const noexcept
{
	return (RED "Form grade is too Low!" RESET);
}


std::ostream &operator<<(std::ostream &os, Form form)
{
	os << "Form " << form.getName() << " has sign grade " << form.getSignGrade();
	os << " and execute grade " << form.getExecuteGrade() << " and is ";
	form.getSigned() ? os << GREEN "signed " RESET : os << RED "not signed " RESET;
	return (os);
}
