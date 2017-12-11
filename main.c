/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:57:29 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/09 17:43:47 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_vm *mlx;

	if (!(mlx = (t_vm*)malloc(sizeof(t_vm))))
		return (-1);
	if (!(mlx->map = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	get_co_ordinates(argc, argv, &mlx->map);
	get_pixels(argv, &mlx->map);
	mlx->x_win = 1000;
	mlx->y_win = 1000;
	mlx->x_ofset = mlx->x_win * 50 / 100;
	mlx->y_ofset = mlx->y_win * 50 / 100;
	mlx->y_tile_hight = 4;
	mlx->x_tile_width = 4;
	mlx->scale = 1;
	mlx->dots_lines = 1;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->y_win, mlx->x_win, "fdf_window");
	run_map(&mlx);
	mlx_mouse_hook(mlx->win, my_key_funct, 0);
	mlx_key_hook(mlx->win, my_key_funct, &mlx);
	mlx_loop(mlx->mlx);
	return (0);
}