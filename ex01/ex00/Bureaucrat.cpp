/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/16 13:01:07 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define Bureacrati ::std

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	try
	{
		if (grade < 1 || grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName(void)
{
	return (this->_name);
}

int Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(int increment)
{
	try
	{
		if (this->_grade - increment < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_grade -= increment;
}

void Bureaucrat::decrementGrade(int decrement)
{
	try
	{
		if (this->_grade + decrement > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_grade += decrement;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ". " << std::endl;
	return (os);
}
