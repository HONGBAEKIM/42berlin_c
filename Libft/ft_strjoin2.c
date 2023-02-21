/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:07:49 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/06 11:10:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
in Get_next_line project, TIMEOUT was happend.
So I have changed ft_strjoin code.

ℹ Running tests: gnlTester (https://github.com/Tripouille/gnlTester)
[Mandatory]
[BUFFER_SIZE = 1]: 
Invalid fd: 1.OK 2.OK 3.OK 
files/empty: 1.OK 2.OK 
files/nl: 1.OK 2.OK 
files/41_no_nl: 1.OK 2.OK 
files/41_with_nl: 1.OK 2.OK 3.OK 
files/42_no_nl: 1.OK 2.OK 
files/42_with_nl: 1.OK 2.OK 3.OK 
files/43_no_nl: 1.OK 2.OK 
files/43_with_nl: 1.OK 2.OK 3.OK 
files/multiple_nlx5: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 
files/multiple_line_no_nl: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 
files/multiple_line_with_nl: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 
files/alternate_line_nl_no_nl: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 
files/alternate_line_nl_with_nl: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 
files/big_line_no_nl: 1.TIMEOUT
1.TIMEOUT
files/big_line_with_nl: 1.TIMEOUT
stdin: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	ft_strlcpy(&str[0], s1, len_s1 + 1);
	ft_strlcpy(&str[len_s1], s2, len_s2 + 1);
	return (str);
}
