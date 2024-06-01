/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:36:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/01 14:04:06 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define PINK "\033[95m"
#define RESET "\033[0m"

class	Bureaucrat;

class Form
{
  private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _executeGrade;

  public:
	Form();
	Form(const std::string &name, int signGrade);
	~Form();
	const std::string getName(void);
	bool getSigned(void);
	int getSignGrade(void);
	int getExecuteGrade(void);
	void beSigned(Bureaucrat &bureaucrat);
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
};

std::ostream &operator<<(std::ostream &os, Form form);