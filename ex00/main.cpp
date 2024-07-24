/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:21 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/04 14:30:50 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << PINK "\n--throw exception when calling constructor with grade too high--" RESET << std::endl;
	{
		try
		{
			Bureaucrat Adam("Adam", 0);
			std::cout << std::endl << Adam << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << PINK "\n--throw exception when calling constructor with grade too low--" RESET << std::endl;
	{
		try
		{
			Bureaucrat Adam("Adam", 151);
			std::cout << std::endl << Adam << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << PINK "\n--throw exception when calling incrementGrade --" RESET << std::endl;
	{
		try
		{
			Bureaucrat Bob("Bob", 2);
			std::cout << std::endl << Bob << std::endl;
			Bob.incrementGrade();
			std::cout << Bob;
			Bob.incrementGrade();
			std::cout  << std::endl << Bob << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << PINK "\n--throw exception when calling decrementGrade--" RESET << std::endl;
	{
		try
		{
			Bureaucrat Bob("Bob", 148);
			std::cout << std::endl << Bob << std::endl;
			Bob.decrementGrade(3);
			std::cout << Bob << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}