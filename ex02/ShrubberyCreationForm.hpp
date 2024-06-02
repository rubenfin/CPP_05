/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:08 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 17:45:06 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
	static const int scSignGrade = 145;
	static const int scExecGrade = 137;
	std::string _target;

  public:
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();
	std::string getTarget(void) const;
	void executeForm(void) const;
};
