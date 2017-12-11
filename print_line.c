/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:42:33 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/09 18:03:19 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print(t_vm **mlx, t_dda **dda, float z)
{
	int	i;

	i = 0;
	while (i <= (*dda)->steps)
	{
		if (z < 0)
			mlx_pixel_put((*mlx)->mlx, (*mlx)->win,
			(*dda)->x, (*dda)->y, 0xff0000);
		else if (z > 0)
			mlx_pixel_put((*mlx)->mlx, (*mlx)->win,
			(*dda)->x, (*dda)->y, 0x00ff00);
		else
			mlx_pixel_put((*mlx)->mlx, (*mlx)->win,
			(*dda)->x, (*dda)->y, 0x0000ff);
		(*dda)->x += (*dda)->x_inc;
		(*dda)->y += (*dda)->y_inc;
		i++;
	}
}

void		print_line(t_vm **mlx, t_plot plot, float z)
{
	t_dda	*dda;

	dda = (t_dda*)malloc(sizeof(t_dda));
	dda->dx = plot.x2 - plot.x1;
	dda->dy = plot.y2 - plot.y1;
	if (ft_abs(dda->dx) > ft_abs(dda->dy))
		dda->steps = ft_abs(dda->dx);
	else
		dda->steps = ft_abs(dda->dy);
	dda->x_inc = dda->dx / (float)dda->steps;
	dda->y_inc = dda->dy / (float)dda->steps;
	dda->x = plot.x1;
	dda->y = plot.y1;
	print(mlx, &dda, z);
}