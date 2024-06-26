/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:35:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/06/02 20:43:11 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form form = Form("test", 150);
        Bureaucrat Jack = Bureaucrat("Jack", 24);
        form.beSigned(Jack);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    
    try
    {
        Form test = Form("test", 125);
        Bureaucrat john = Bureaucrat("John", 125);

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
