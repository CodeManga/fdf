/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_co_ordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:59:40 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/09 17:34:30 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		width_len(char *buff)
{
	int		width;
	int		index;

	width = 0;
	index = 0;
	while (buff[index])
	{
		while ((ft_isblank(buff[index]) || buff[index] == '-') && buff[index])
			index++;
		if (ft_isdigit(buff[index]))
		{
			width++;
			while (ft_isdigit(buff[index]) && buff[index])
				index++;
		}
	}
	return (width);
}

void	get_co_ordinates(int argc, char **argv, t_map **map)
{
	(*map)->fd = open(argv[1], O_RDONLY);
	(*map)->width = 0;
	(*map)->line = NULL;
	(*map)->hight = 0;
	if (argc == 2)
	{
		if ((get_next_line((*map)->fd, &(*map)->line)) > 0)
		{
			(*map)->width = width_len((*map)->line);
			(*map)->hight++;
		}
		else
			return ;
		while ((get_next_line((*map)->fd, &(*map)->line)) > 0)
		{
			if ((*map)->width)
				(*map)->hight++;
		}
	}
	close((*map)->fd);
}