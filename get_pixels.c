/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:06:14 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/09 17:41:54 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	convert_line(t_map **map)
{
	while ((*map)->spltlyn[(*map)->x])
	{
		(*map)->val[(*map)->y][(*map)->x] =
			(float)ft_atoi((*map)->spltlyn[(*map)->x]);
		if (((*map)->x + 1) == (*map)->width)
		{
			while ((*map)->spltlyn[(*map)->x])
				(*map)->x++;
			break ;
		}
		(*map)->x++;
	}
}

static void	get_line(t_map **map)
{
	while ((get_next_line((*map)->fd, &(*map)->line)) > 0)
	{
		(*map)->spltlyn = ft_strsplit((*map)->line, ' ');
		(*map)->x = 0;
		if ((*map)->y > 0)
		{
			if (width_len((*map)->line) < (*map)->width)
			{
				free((*map)->val);
				close((*map)->fd);
				ft_putendl("error in reading map");
				exit(-1);
			}
		}
		convert_line(map);
		if (((*map)->y + 1) == (*map)->hight)
			break ;
		(*map)->y++;
	}
}

void		get_pixels(char **argv, t_map **map)
{
	(*map)->y = 0;
	(*map)->val = NULL;
	(*map)->line = NULL;
	(*map)->fd = open(argv[1], O_RDONLY);
	(*map)->val = (float**)malloc(sizeof(float*) * (*map)->hight);
	while ((*map)->y < (*map)->hight)
	{
		(*map)->val[(*map)->y] = (float*)malloc(sizeof(float) * (*map)->width);
		(*map)->y++;
	}
	(*map)->y = 0;
	get_line(map);
	close((*map)->fd);
	(*map)->y = 0;
}