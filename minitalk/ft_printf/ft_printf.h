/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:46:51 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 18:46:52 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c, int *len);
int	ft_putstr(char *str, int *len);
int	ft_print_memory(void *addr, int *len);
int	ft_putnbr(int n, int *len);
int	ft_putnbr_u(unsigned int n, int *len);
int	ft_puthex(int n, char c, int *l);

#endif
