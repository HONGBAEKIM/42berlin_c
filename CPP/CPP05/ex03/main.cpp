/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 17:04:40 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip>

static void     printTitle(std::string title)
{
        std::string     toPrint;
        int     size = 72;
        int     n;

        toPrint = " " + title + " ";
        n = toPrint.size();
        std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
        std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
        std::cout << toPrint.substr(n / 2, n - n / 2);
        std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
        std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}

int	main(void)
{
	srand(time(NULL));

	printTitle("Formular Creation");
	Bureaucrat	pres("President", 1);
	Intern		SadIntern;
	AForm		*forms[4];

	forms[0] = SadIntern.makeForm("shrubbery creation", "Target1");
	forms[1] = SadIntern.makeForm("robotomy request", "Target2");
	forms[2] = SadIntern.makeForm("presidential pardon", "Target3");
	forms[3] = SadIntern.makeForm("formular", "Target4");

	for (int i = 0; i < 4; i++)
	{
		if (forms[i])
		{
			std::cout << std::endl << *(forms[i]);
			pres.signForm(*(forms[i]));
			pres.executeForm(*(forms[i]));
		}
	}

	for (int i = 0; i < 4; i++)
		delete forms[i];
	return (0);
}


/* static void     printTitle(std::string title)
{
        std::string     toPrint;
        int     size = 72;
        int     n;

        toPrint = " " + title + " ";
        n = toPrint.size();
        if (n > size)
        {
                toPrint = toPrint.substr(0, size - 2);
				std::cout << len(toPrint) << std::endl;
                toPrint[size - 4] = '.';
                toPrint[size - 3] = ' ';
                n = toPrint.size();
        }
        std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
        std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
        std::cout << toPrint.substr(n / 2, n - n / 2);
        std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
        std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
} */

