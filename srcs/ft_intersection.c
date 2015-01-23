/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:56:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/23 18:34:05 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>

#include <libft.h>

int		ft_distance(int x1, int y1, int x2, int y2)
{
	double pow1;
	double pow2;

	pow1 = pow((double)(x1 - x2), 2);
	pow2 = pow((double)(y1 - y2), 2); 
	return((int)(sqrt(pow1+pow2)));
}

int		inter_vertical(t_map *map, t_pdata *pdata, double alpha)
{
	t_coord	a;
	int		Ya;
	int		Xa;

	a.x = pdata->coord->y / 64 * 64;
	a.x = ((alpha > 270 && alpha < 90) ? a.x + 64 : a.x -1);
	Xa = ((alpha > 270 && alpha < 90) ? +64 : -64);
	Ya = 64 * tan(alpha * M_PI / 180);
	a.y = pdata->coord->y + (pdata->coord->x - a.x) * tan(alpha * M_PI / 180);
	ft_putendl("before");
	ft_putendl(ft_itoa(map->height));
	ft_putendl(ft_itoa(map->width));
	ft_putendl(ft_itoa(a.y / 64));
	ft_putendl(ft_itoa(a.x / 64));
	ft_putendl(ft_itoa(map->map[a.y/64][a.x/64]));
	while ( map->height < a.y / 64 && map->width < a.x / 64
			&& map->map[a.y / 64][a.x / 64] != '1')
	{	
		ft_putendl(ft_itoa(Xa));
		ft_putendl(ft_itoa(Ya));
		
		ft_putendl("boucle");		
		a.x = a.x + Xa;
		a.y = a.y + Ya;
	}
	ft_putendl("after");
	return((ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180)));
}

int		inter_horizontal(t_map *map, t_pdata *pdata, double alpha)
{
	t_coord	a;
	int		Ya;
	int		Xa;

	if ( alpha == 0 )
		alpha = 0.00001;
	a.y = pdata->coord->y / 64 * 64;
	a.y = ((alpha > 0 && alpha < 180) ? a.y - 1 : a.y + 64);
	Ya = ((alpha > 0 && alpha < 180) ? -64 : 64);
	Xa = 64 / tan(alpha * M_PI / 180);
	a.x = pdata->coord->x + (pdata->coord->y - a.y) / tan(alpha * M_PI / 180);
	while ( map->height < a.y / 64 && map->width < a.x / 64
			&& map->map[a.y / 64][a.x / 64] != '1')
	{			
		a.x = a.x + Xa;
		a.y = a.y + Ya;
	}
	return(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180));
}
