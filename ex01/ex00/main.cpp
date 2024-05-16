/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:21 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/16 11:48:51 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat b("Johnny", 23623);
    std::cout << b;
    b.incrementGrade(200);
    std::cout << b;
    return (0);
}