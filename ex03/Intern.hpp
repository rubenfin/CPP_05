/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 18:14:53 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 09:41:32 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>
#include <functional>

class Intern
{
  public:
	Intern(void);
	~Intern();
	AForm *makeForm(const std::string &formName, const std::string &target);
	class FormNotFoundException : public std::exception
	{
		public:
		const char *what(void) const noexcept override;
	};
};
