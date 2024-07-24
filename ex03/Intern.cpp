/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 18:14:45 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 11:27:13 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

template <typename FormType>
AForm* createForm(const std::string& target) {
    return new FormType(target);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target )
{
	std::map<std::string, std::function<AForm*()>> findForm;
    findForm["presidential pardon"] = [&target]() { return createForm<PresidentialPardonForm>(target); };
    findForm["shrubbery creation"] = [&target]() { return createForm<ShrubberyCreationForm>(target); };
    findForm["robotomy request"] = [&target]() { return createForm<RobotomyRequestForm>(target); };

    auto it = findForm.find(formName);
        if (it != findForm.end())
            return it->second();
        else {
            throw Intern::FormNotFoundException();           
        }
}

Intern::~Intern()
{
}

const char *Intern::FormNotFoundException::what(void) const noexcept
{
	return (RED "Form has not been found!" RESET);
}