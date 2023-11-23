#include "Bureaucrat.hpp"

void	testBasic(void)
{
	Bureaucrat	ABCD("ABCD", 6);

	std::cout << ABCD << std::endl;
	ABCD.downGrade();
	std::cout << ABCD << std::endl;
	ABCD.upGrade();
	ABCD.upGrade();
	ABCD.upGrade();
	ABCD.upGrade();
	std::cout << ABCD << std::endl;
}

void	testExceptionLow(void)
{
	Bureaucrat	ABCD("ABCD", 151);
}

void	testExceptionHigh(void)
{
	Bureaucrat	ABCD("ABCD", 0);
}

void	testDownGrade(void)
{
	Bureaucrat	ABCD("ABCD", 2);
	std::cout << ABCD << std::endl;
    ABCD.upGrade();
	std::cout << ABCD << std::endl;
	ABCD.upGrade();
	std::cout << ABCD << std::endl;
}

void	testUpGrade(void)
{
	Bureaucrat	ABCD("ABCD", 149);
	std::cout << ABCD << std::endl;
	ABCD.downGrade();
	std::cout << ABCD << std::endl;
	ABCD.downGrade();
	std::cout << ABCD << std::endl;
}

int	main(void)
{
	try
	{
		testBasic();
	}
	catch (std::exception &e)
	{
	    std::cout << "testBasic" << std::endl;
        std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionLow();
	}
	catch (std::exception &e)
	{
	    std::cout << "testExceptionLow" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionHigh();
	}
	catch (std::exception &e)
	{
	    std::cout << "testExceptionHigh" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		testDownGrade();
	}
	catch (std::exception &e)
	{
	    std::cout << "testDownGrade" << std::endl;
        std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testUpGrade();
	}
	catch (std::exception &e)
	{
	    std::cout << "testUpGrade" << std::endl;
        std::cerr << e.what() << std::endl;
	}

	return (0);
}
