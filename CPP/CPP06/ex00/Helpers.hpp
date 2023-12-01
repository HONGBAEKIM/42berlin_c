/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:29:27 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/29 15:31:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_HPP
# define HELPERS_HPP
# include <string>

bool isSpecial(std::string const &val);
bool isFloat(std::string const &val);
bool isDouble(std::string const &val);
bool isInteger(std::string const &val);

#endif
