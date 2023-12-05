/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:01:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/05 14:01:48 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	array1[] = {1, 2, 3, 4, 5};
	iter<int>(array1, 5, &print);
	std::cout << std::endl;
	iter<int>(array1, 5, &addone);
	iter<int>(array1, 5, &print);
	std::cout << std::endl;
	iter<int>(array1, 5, &addone);
	iter<int>(array1, 5, &print);
	std::cout << std::endl;

	char	array2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	iter<char>(array2, 7, &print);
	std::cout << std::endl;
	iter<char>(array2, 7, &addone);
	iter<char>(array2, 7, &print);
	std::cout << std::endl;
	iter<char>(array2, 7, &addone);
	iter<char>(array2, 7, &print);
	std::cout << std::endl;

	float	array3[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	iter<float>(array3, 5, &print);
	std::cout << std::endl;
	iter<float>(array3, 5, &addone);
	iter<float>(array3, 5, &print);
	std::cout << std::endl;
	iter<float>(array3, 5, &addone);
	iter<float>(array3, 5, &print);
	std::cout << std::endl;

	return (0);
}
