/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:25 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/16 12:55:32 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define PINK "\033[95m"
#define RESET "\033[0m"

class Bureaucrat
{
  public:
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const noexcept override
		{
			return ("Grade is too high!");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const noexcept override
		{
			return ("Grade is too high!");
		}
	};
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	const std::string getName(void);
	int getGrade(void);
	void incrementGrade(int increment);
	void decrementGrade(int decrement);

  private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat obj);
