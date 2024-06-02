/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 16:36:05 by rfinneru      ########   odam.nl         */
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "bureaucrat " << this->_name << " has passed away..." << std::endl;
}

const std::string Bureaucrat::getName(void)
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

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_signGrade - 1 < 1)
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
		if (this->_signGrade - increment < 1)
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
		if (this->_signGrade + 1 > 150)
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
		if (this->_signGrade + decrement > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_signGrade += decrement;
}

bool Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
	{
		std::cout << this->getName() << " tried to sign " << form.getName() << " but the form is already signed! " << std::endl;
		return (false);
	}
	if (form.getSignGrade() < this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
	return (true);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	if (!form.getSigned())
	{
		std::cout << this->_name << " is currently " RED << "not signed " RESET << std::endl;
		return ;
	}	
	if (form.getExecuteGrade() < this->_execGrade)
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_name << " executed " << form.getName() << std::endl;
	form.executeForm();
}

const char *Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return (RED "Grade is too High!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return (RED "Grade is too Low!" RESET);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getSignGrade() << ". " << std::endl;
	return (os);
}
