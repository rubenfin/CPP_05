/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 16:56:40 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	static const int ppSignGrade = 25;
	static const int ppExecGrade = 5;
	std::string _target;

  public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();
	std::string getTarget(void) const;
	void executeForm(void) const;
};
