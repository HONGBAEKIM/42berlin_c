/* 
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
*/

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!*begin_list || !begin_list)
		return ;
	t_list	*cur = *begin_list;
	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		if (cur->next == NULL)
			return ;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}



void	print_list(t_list **begin_list)
{
	t_list	*cur = *begin_list;

	while (cur)
	{
		printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
}

int	main()
{
	char	str1[] = "a";
	char	str2[] = "b";
	char	str3[] = "a";
	char	str4[] = "d";

	t_list	*aa = malloc(sizeof(t_list));
	aa->data = str1;
	t_list	*bb = malloc(sizeof(t_list));
	aa->next = bb;
	bb->data = str2;
	t_list	*cc = malloc(sizeof(t_list));
	bb->next = cc;
	cc->data = str3;
	t_list	*dd = malloc(sizeof(t_list));
	cc->next = dd;
	dd->data = str4;
	//dd->next = 0;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("\n");
	ft_list_remove_if(begin_list, str1, ft_strcmp);
	print_list(begin_list);
}

