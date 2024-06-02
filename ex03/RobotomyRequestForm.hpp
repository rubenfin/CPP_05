/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:05 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 16:56:42 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <random>

class RobotomyRequestForm : public AForm
{
  private:
	static const int rrSignGrade = 72;
	static const int rrExecGrade = 45;
	std::string _target;

  public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();
	std::string getTarget(void) const;
	void executeForm(void) const;
};
