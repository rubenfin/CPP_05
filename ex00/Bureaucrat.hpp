/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:25 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/17 13:42:45 by rfinneru      ########   odam.nl         */
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
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	const std::string getName(void);
	int getGrade(void);
	void incrementGrade(void);
	void incrementGrade(int increment);
	void decrementGrade(void);
	void decrementGrade(int decrement);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what(void) const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what(void) const noexcept override;
	};

  private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat obj);
