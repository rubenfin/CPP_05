/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/03 14:50:51 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int signGrade,
	int executeGrade) : _name(name), _signGrade(signGrade),
	_execGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Made bureaucrat " << getName() << " with sign Grade " << getSignGrade() << " and execute Grade " << getExecuteGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	std::cout << "Bureaucrat Copy constructor called!" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_signGrade = other._signGrade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "bureaucrat " << this->_name << " has passed away..." << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Bureaucrat::getExecuteGrade(void) const
{
	return (this->_execGrade);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	if (!form.getSigned())
		throw AForm::FormNotSignedException();
	if (form.getExecuteGrade() < this->_execGrade)
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_name << " executed " << form.getName() << std::endl;
	form.executeForm();
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if ((this->_signGrade - 1) < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_signGrade--;
}

void Bureaucrat::incrementGrade(int increment)
{
	try
	{
		if ((this->_signGrade - increment) < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_signGrade -= increment;
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if ((this->_signGrade + 1) > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_signGrade++;
}

void Bureaucrat::decrementGrade(int decrement)
{
	try
	{
		if ((this->_signGrade + decrement) > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_signGrade += decrement;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
		throw AForm::FormAlreadySignedException();
	if (form.getSignGrade() < this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return (RED "Grade is too High!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return (RED "Grade is too Low!" RESET);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade ";
	os << bureaucrat.getSignGrade() << ". " << std::endl;
	return (os);
}
