/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:23:05 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/11 12:41:55 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	direction(int keycode, t_vm **mlx)
{
	if (keycode == 124 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->x_ofset += 20;
		run_map(mlx);
	}
	else if (keycode == 123 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->x_ofset -= 20;
		run_map(mlx);
	}
	else if (keycode == 126 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->y_ofset -= 20;
		run_map(mlx);
	}
	else if (keycode == 125 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->y_ofset += 20;
		run_map(mlx);
	}
}

static void	zoom(int keycode, t_vm **mlx)
{
	if (keycode == 69 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->y_tile_hight += 1;
		(*mlx)->x_tile_width += 1;
		(*mlx)->scale *= 1.2;
		(*mlx)->x_ofset -= 4;
		(*mlx)->y_ofset -= 10;
		run_map(mlx);
	}
	else if (keycode == 78 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->y_tile_hight--;
		(*mlx)->x_tile_width--;
		(*mlx)->scale /= 1.2;
		(*mlx)->x_ofset += 4;
		(*mlx)->y_ofset += 10;
		run_map(mlx);
	}
}

static void	scale_dot(int keycode, t_vm **mlx)
{
	if (keycode == 116 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->scale += 0.5;
		run_map(mlx);
	}
	else if (keycode == 121 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		(*mlx)->scale -= 0.5;
		run_map(mlx);
	}
	else if (keycode == 81 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
	{
		if ((*mlx)->dots_lines == 1)
			(*mlx)->dots_lines = 0;
		else if ((*mlx)->dots_lines == 0)
			(*mlx)->dots_lines = 1;
		run_map(mlx);
	}
}

static void	extra_tools(int keycode, t_vm **mlx)
{
	if (keycode == 67 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
		(*mlx)->y_tile_hight /= 2;
	else if (keycode == 75 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
		(*mlx)->x_tile_width /= 2;
	else if (keycode == 83 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
		(*mlx)->y /= 2;
	else if (keycode == 67 && (mlx_clear_window((*mlx)->mlx, (*mlx)->win)))
		(*mlx)->y /= 2;
}

int			my_key_funct(int keycode, t_vm **mlx)
{
	if (keycode == 53)
	{
		free((*mlx)->map);
		free((*mlx)->map->val);
		free((*mlx)->map);
		free(*mlx);
		exit(1);
	}
	direction(keycode, mlx);
	zoom(keycode, mlx);
	scale_dot(keycode, mlx);
	extra_tools(keycode, mlx);
	return (0);
}