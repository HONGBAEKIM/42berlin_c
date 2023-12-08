/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:54:57 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/08 17:04:37 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    //Array Initialization
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    //Values Population
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        //Create an array of integers with size as 'number', which is 750 
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        //Comparison
		if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		//added else
		else
		{
			std::cout << "value " << i << " is " << mirror[i] << std::endl;
		}
    }
	//added for
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = i;
		std::cout << "Now numbers is " << numbers[i] << " and mirror is still ";
		std::cout << mirror[i] << std::endl;
	}
    
	//to check 1 option of exception
	try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
	//to check 2 option of exception
	try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	//Repopulate the numbers array with new random valdues
	//after various operations, tests, and modifications have been performed.
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	
    //Deallocates the dynamically allocated memory
	delete [] mirror;
    return 0;
}
