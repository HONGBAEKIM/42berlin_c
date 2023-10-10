/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_readutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:21:26 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 11:41:10 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_char(cub_main *cub)
{
	char	onechar;
	int		num_chars_read;

	num_chars_read = read(cub->fd, &onechar, 1);
	if (num_chars_read < 1)
		ft_error(ERR_READ, cub);
	cub->total_chars_read += num_chars_read;
	cub->char_read = onechar;
	//printf("cub->char_read :  %c\n", cub->char_read);
//	cub->char_read = onechar[0];
}

bool	match_char(cub_main *cub, char char_to_match)
{
	if (cub->char_read == char_to_match)
		return (1);
	return (0);
}

bool	*choose_fileflag(cub_main *cub, char *path)
{
	if (!ft_strcmp(path, "NO"))
		return (&cub->fileflags.no);
	if (!ft_strcmp(path, "SO"))
		return (&cub->fileflags.so);
	if (!ft_strcmp(path, "WE"))
		return (&cub->fileflags.we);
	if (!ft_strcmp(path, "EA"))
		return (&cub->fileflags.ea);
	if (!ft_strcmp(path, "F"))
		return (&cub->fileflags.f);
	if (!ft_strcmp(path, "C"))
		return (&cub->fileflags.c);
	return (NULL);
}

void	read_prefixes(cub_main *cub)
{
	read_char(cub);
	while (cub->char_read == '\n')
		read_char(cub);
	if (read_tex_prefix(cub, "NO"))
		return ;
	if (read_tex_prefix(cub, "SO"))
		return ;
	if (read_tex_prefix(cub, "WE"))
		return ;
	if (read_tex_prefix(cub, "EA"))
		return ;
	if (read_color_prefix(cub, "F"))
		return ;
	if (read_color_prefix(cub, "C"))
		return ;
	ft_error(ERR_PREFIXES, cub);
}

