/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/17 13:36:58 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define Bureacrati ::std

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
	_grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Made bureaucrat " << getName() << " with grade " << getGrade() << std::endl;  
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

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_grade--;
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

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	this->_grade++;
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
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ". " << std::endl;
	return (os);
}
