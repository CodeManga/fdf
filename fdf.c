/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:56:33 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/09 18:14:18 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	z_effect(t_vm **mlx, int i, int j)
{
	(*mlx)->y_z = (((*mlx)->y_ofset + ((((*mlx)->y +
		(*mlx)->x) / 2)) * (*mlx)->y_tile_hight));
	(*mlx)->x_z = (((*mlx)->x_ofset + (((*mlx)->x -
		(*mlx)->y)) * (*mlx)->x_tile_width));
	if ((*mlx)->z != 0)
		(*mlx)->y_z -= (*mlx)->z * (*mlx)->scale;
	if ((*mlx)->dots_lines == 1)
	{
		if ((*mlx)->z > 0)
			mlx_pixel_put((*mlx)->mlx, (*mlx)->win, (*mlx)->x_z,
				(*mlx)->y_z, 0xFF0000);
		else if ((*mlx)->z < 0)
			mlx_pixel_put((*mlx)->mlx, (*mlx)->win, (*mlx)->x_z,
				(*mlx)->y_z, 0x00FF00);
		else
			mlx_pixel_put((*mlx)->mlx, (*mlx)->win, (*mlx)->x_z,
				(*mlx)->y_z, 0x0000FF);
	}
}

static void	modify_cord(t_vm **mlx, t_cord cord)
{
	int		i;
	int		j;

	(*mlx)->y = -1;
	j = 0;
	while (++(*mlx)->y < (*mlx)->map->hight)
	{
		(*mlx)->x = -1;
		i = 0;
		while (++(*mlx)->x < (*mlx)->map->width)
		{
			(*mlx)->z = (*mlx)->map->val[j][i];
			z_effect(mlx, i, j);
			cord.y_val[j][i] = (*mlx)->y_z;
			cord.x_val[j][i] = (*mlx)->x_z;
			i++;
		}
		j++;
	}
}

static void x_cord_print(t_vm **mlx, t_cord cord, t_plot plot)
{
	int	x;
	int	y;
	y = -1;
	while (++y < ((*mlx)->map->hight))
	{
		x = -1;
		while (++x < (*mlx)->map->width - 1)
		{
			plot.x1 = cord.x_val[y][x];
			plot.y1 = cord.y_val[y][x];
			plot.x2 = cord.x_val[y][x + 1];
			plot.y2 = cord.y_val[y][x + 1];
			print_line(mlx, plot, (*mlx)->map->val[y][x]);
		}
	}
}

static void	print(t_vm **mlx, t_cord cord)
{
	int	x;
	int	y;
	t_plot plot;
	
	x_cord_print(mlx, cord, plot);
	x = -1;
	while (++x < (*mlx)->map->width)
	{
		y = -1;
		while (++y < ((*mlx)->map->hight) - 1)
		{
			plot.x1 = cord.x_val[y][x];
			plot.y1 = cord.y_val[y][x];
			plot.x2 = cord.x_val[y + 1][x];
			plot.y2 = cord.y_val[y + 1][x];
			print_line(mlx, plot, (*mlx)->map->val[y][x]);
		}
	}
}

void		run_map(t_vm **mlx)
{
	int		i;
	int		j;
	t_cord	cord;

	cord.x_val = (float**)malloc(sizeof(float*) * (*mlx)->map->hight);
	cord.y_val = (float**)malloc(sizeof(float*) * (*mlx)->map->hight);
	i = -1;
	while (++i < (*mlx)->map->width)
	{
		cord.x_val[i] = (float*)malloc(sizeof(float) * (*mlx)->map->width);
		cord.y_val[i] = (float*)malloc(sizeof(float) * (*mlx)->map->width);
	}
	modify_cord(mlx, cord);
	if ((*mlx)->dots_lines == 0)
		print(mlx, cord);
}