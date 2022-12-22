/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:40 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/22 11:18:43 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	/*    printf("%"); */
	/* ft_printf("32 This is an int : %0d\n\n", 0); */
	/*    printf("32 This is an int : %0d\n\n", 0); */
	/* ft_printf("{%05.*d}\n", -15, 42); */
	/*    printf("{%05.*d}\n", -15, 42); */
	/* printf("%010p\n", 0x1); */
	/* ft_printf("%010p\n", 0x1); */
	/* ft_printf("%050 d\n", 500); */
	/*    printf("%050 d\n", 500); */
	/* ft_printf("%020.5s\n", "Hallo heimur"); */
	/*    printf("%020.5s\n", "Hallo heimur"); */
	/* ft_printf("bonjour%nyi", &test); */
	/* ft_printf("%hi\n", 32768); */
    /*    printf("%hi\n", 32768); */
	/* ft_printf("%.37ld", -22337203685477l); */
    /*  */
	/* ft_printf("[%]\n"); */
	/*    printf("[%]\n"); */
	/* ft_printf("[%5]\n"); */
	/*    printf("[%5]\n"); */
	/* ft_printf("[%05]\n"); */
	/*    printf("[%05]\n"); */
	/* int test = 42; */
	/* ft_printf("bonjour\n"); */
    /* ft_printf("char:                    %c\n", 'r'); */
    /* ft_printf("string:                  %s\n", "bonjour"); */
    /* ft_printf("pointer:                 %p\n", &test); */
    /* ft_printf("int:                     %d or %i\n", 45, 54); */
    /* ft_printf("uint:                    %u\n", 1 << 31); */
    /* ft_printf("hex lower:               %x\n", 0xabcf012); */
    /* ft_printf("hex upper:               %X\n", 0xabcf012); */
    /* ft_printf("percent:                 %%\n"); */
	/* ft_printf("multiple stuff:          %d %u %d %x %d\n", 1, -2, 3, 0xa, 5); */
    /*  */
	/* ft_printf("precision                |%.9d|\n", 43); */
	/*    printf("precision                |%.9d|\n", 43); */
	/* ft_printf("string precision         |%.9s|\n", "jesuisbonjourbonjour"); */
	/*    printf("string precision         |%.9s|\n", "jesuisbonjourbonjour"); */
	/* ft_printf("min width                |%9d|\n", 43); */
	/*    printf("min width                |%9d|\n", 43); */
	/* ft_printf("zero padding             |%09d|\n", 43); */
	/*    printf("zero padding             |%09d|\n", 43); */
	/* ft_printf("left adjusted            |%-9d|\n", 43); */
	/*    printf("left adjusted            |%-9d|\n", 43); */
	/* ft_printf("string padding           |%9s|\n", "bon"); */
	/*    printf("string padding           |%9s|\n", "bon"); */
    /*  */
	/* ft_printf("width wildcard           |%*d|\n", 5, 43); */
	/*    printf("width wildcard           |%*d|\n", 5, 43); */
	/* ft_printf("precision wildcard       |%.*d|\n", 5, 43); */
	/*    printf("precision wildcard       |%.*d|\n", 5, 43); */
	/* ft_printf("precision/width wildcard |%*.*d|\n", 5, 3, 43); */
	/*    printf("precision/width wildcard |%*.*d|\n", 5, 3, 43); */
	/* ft_printf("left adjusted            |%*d|\n", -5, 43); */
	/*    printf("left adjusted            |%*d|\n", -5, 43); */
	/* ft_printf("overwrite                |%*3d|\n", 5, 43); */
	   /* printf("overwrite                |%*3d|\n", 5, 43); */
	/* ft_printf("overwrite neg            |%*-1d|\n", 0, 43); */
	/*    printf("overwrite neg            |%*-1d|\n", 0, 43); */
    /* ft_printf("pointer field width      |%15p|\n", &test); */
    /*    printf("pointer field width      |%15p|\n", &test); */
	/* ft_printf("bonjour%n", &test); */
	/* printf("%d\n", test); */
	ft_printf("%.0p, %.p", 0, 0);
	/* ft_printf("%f\n", 0.14159); */
	/*    printf("%f\n", 0.14159); */
	/* ft_printf("%f\n", 3.14159); */
	/*    printf("%f\n", 3.14159); */
	/* ft_printf("%f\n", -3.14159); */
	/* ft_printf("%f\n", 334.141519); */
	/* ft_printf("%lf\n", 212.0); */
	/*    printf("%lf\n", 212.0); */
	/*    printf("%f\n", 212.0); */
    return (0);
}