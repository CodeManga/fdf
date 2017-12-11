/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:57:09 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/11 12:43:45 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_map
{
	float	width;
	float	hight;
	char	*line;
	int		fd;
	int		x;
	int		y;
	float	**val;
	char	**spltlyn;
}				t_map;

typedef struct	s_dda
{
	float	x;
	float	y;
	float	dy;
	float	dx;
	int		steps;
	float	x_inc;
	float	y_inc;
}				t_dda;

typedef struct	s_cord
{
	float	**x_val;
	float	**y_val;
}				t_cord;

typedef struct	s_plot
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}				t_plot;

typedef struct	s_vm
{
	void			*mlx;
	void			*win;
	float			x;
	float			y;
	float			z;
	float			y_z;
	float			x_z;
	float			slope;
	int				x_win;
	int				y_win;
	float			y_ofset;
	float			x_ofset;
	float			y_tile_hight;
	float			x_tile_width;
	float			scale;
	int				dots_lines;
	struct s_map	*map;
}				t_vm;

void	run_map(t_vm **mlx);
int		my_key_funct(int keycode, t_vm **mlx);
void	get_co_ordinates(int argc, char **argv, t_map **map);
int		width_len(char *buff);
void	get_pixels(char **argv, t_map **map);
int		my_key_funct(int keycode, t_vm **mlx);
int		ft_abs(int value);
void	print_line(t_vm **mlx, t_plot plot, float z);
int		ft_abs(int value);
void	free_2d(char **array, int num_rows);

#endif