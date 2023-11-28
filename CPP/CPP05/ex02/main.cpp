/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/28 14:31:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

int	main()
{
	//1st test
	printTitle("Shrubbery Creation");
	AForm		*Shrubbery = new ShrubberyCreationForm("home");
	Bureaucrat	corrector("corrector", 1);
	Bureaucrat	Lucie("Lucie", 138);

	corrector.executeForm(*Shrubbery);
	std::cout << *Shrubbery << std::endl;
	std::cout << Lucie << std::endl;
	corrector.signForm(*Shrubbery);
	std::cout << *Shrubbery << std::endl;
	std::cout << Lucie << std::endl;
	corrector.executeForm(*Shrubbery);
	Lucie.executeForm(*Shrubbery);
	Lucie.upGrade();
	std::cout << *Shrubbery << std::endl;
	std::cout << Lucie << std::endl;
	Lucie.executeForm(*Shrubbery);
	delete Shrubbery;



	//random number generator with current time
	std::srand(std::time(0));
	//2ed test
	printTitle("Robotomy Request");
	AForm		*robotomy = new RobotomyRequestForm("corrector");
	Bureaucrat	Lucie2("Lucie2", 1);

	Lucie2.executeForm(*robotomy);
	Lucie2.signForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	Lucie2.executeForm(*robotomy);
	delete robotomy;



	//3rd test
	printTitle("Presidential Pardon");
	AForm		*presidential = new PresidentialPardonForm("corrector");
	Bureaucrat	Lucie3("Lucie3", 6);

	Lucie3.executeForm(*presidential);
	Lucie3.signForm(*presidential);
	Lucie3.executeForm(*presidential);
	Lucie3.upGrade(); 
	Lucie3.executeForm(*presidential);
	delete presidential;

	return (0);
}

/* int	main(void)
{
	srand(time(NULL));

	printTitle("Shrubbery Creation");
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Lucie", 140);

	corr.executeForm(*shrub);
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;


	printTitle("Robotomy Request");
	AForm		*robotomy = new RobotomyRequestForm("Correcteur");
	Bureaucrat	me2("Lucie", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	
	printTitle("Presidential Pardon");
	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	Lucie3("Lucie", 6);

	Lucie3.executeForm(*presidential);
	Lucie3.signForm(*presidential);
	Lucie3.executeForm(*presidential);
	Lucie3.upGrade();
	Lucie3.executeForm(*presidential);
	delete presidential;

	return (0);
}
 */


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

