/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 14:16:26 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

typedef struct s_node
{
	int				contect;
	int				rank;
	struct	s_node	*next;
	struct	s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}			t_stack;




int	main(int ac, char **av)
{
	
}
