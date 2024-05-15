/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/15 14:57:57 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
	try
	{
		/* code */
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
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

void	Bureaucrat::incrementGrade(int increment)
{
    this->_grade--;
}

void	Bureaucrat::decrementGrade(int decrement)
{
    this->_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat obj)
{
    os << obj.getName() << ", bureaucrat grade" << obj.getGrade() << "." << std::endl;
}
