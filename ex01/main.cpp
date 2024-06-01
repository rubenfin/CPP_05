/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:35:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/01 14:23:49 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form test = Form("test", -7686);
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form test = Form("test", 125);
        Bureaucrat john = Bureaucrat("John", 235235);

        test.beSigned(john);
        test.beSigned(john);

        std::cout << test << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
