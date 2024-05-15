/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:25 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/15 14:43:24 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

    const std::string getName(void);
    int getGrade(void);    
};
