/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:37:02 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 20:51:05 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

AForm::AForm(const std::string &name, int signGrade,
	int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade),
	_executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.signForm(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his/her grade is too low!" << std::endl;
		return ;
	}
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (this->_signGrade < executor.getSignGrade()
		|| this->_executeGrade < executor.getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	executor.executeForm(*this);
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}
bool AForm::getSigned(void) const
{
	return (this->_isSigned);
}
int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}
int AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

const char *AForm::GradeTooHighException::what(void) const noexcept
{
	return (RED "Form grade is too High!" RESET);
}

const char *AForm::GradeTooLowException::what(void) const noexcept
{
	return (RED "Form grade is too Low!" RESET);
}

const char *AForm::FormNotSignedException::what(void) const noexcept
{
	return (RED "Form is not yet signed!" RESET);
}

const char *AForm::FormAlreadySignedException::what(void) const noexcept
{
	return (RED "Form is already signed!" RESET);
}