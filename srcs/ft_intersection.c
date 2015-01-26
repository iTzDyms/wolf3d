/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:56:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/26 16:38:34 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>

#include <libft.h>

double	ft_distance(double x1, double y1, double x2, double y2)
{
	double pow1;
	double pow2;

	pow1 = pow((x1 - x2), 2);
	pow2 = pow((y1 - y2), 2); 
	return((sqrt(pow1+pow2)));
}

double		inter_vertical(t_map *map, t_pdata *pdata, double alpha)
{
	t_coord	a;
	double	Ya;
	double	Xa;

	if (alpha == 270 || alpha == 90)
		return(-1);
	a.x = pdata->coord->y / 64 * 64;
	a.x = ((alpha > 270 && alpha < 90) ? a.x + 64 : a.x -1);
	Xa = ((alpha > 270 && alpha < 90) ? +64 : -64);
	Ya = 64 * tan(alpha * M_PI / 180);
	a.y = pdata->coord->y + (pdata->coord->x - a.x) * tan(alpha * M_PI / 180);
	//ft_putendl("before");
	//ft_putendl(ft_itoa(map->height));
	//ft_putendl(ft_itoa(map->width));
	//ft_putendl(ft_itoa(a.y / 64));
	//ft_putendl(ft_itoa(a.x / 64));
	//ft_putendl(ft_itoa(map->map[a.y/64][a.x/64]));
	while ( map->height > a.y / 64 && map->width > a.x / 64 && a.y >= 0 && a.x >= 0)
	{	
	//	ft_putendl(ft_itoa(Xa));
	//	ft_putendl(ft_itoa(Ya));
		
	//	ft_putendl("boucle");		
		if (map->map[(int)a.y / 64][(int)a.x / 64] == '1')
		{
			//ft_putendl(ft_itoa(a.y / 64));//////////
			//ft_putendl(ft_itoa(a.x / 64));/////////
			//ft_putendl(ft_itoa(((ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180)))));
			return((ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y)));// * cos(fabs(pdata->dir - alpha) * M_PI / 180)));
		}
		a.x = a.x + Xa;
		a.y = a.y + Ya;
	}
	return(-1);
	//ft_putendl("after");
	//return((ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180)));
}

double		inter_horizontal(t_map *map, t_pdata *pdata, double alpha)
{
	t_coord	a;
	double	Ya;
	double	Xa;

	if (alpha == 0 || alpha == 180)
		return(-1);
	a.y = pdata->coord->y / 64 * 64;
	a.y = ((alpha > 0 && alpha < 180) ? a.y - 1 : a.y + 64);
	Ya = ((alpha > 0 && alpha < 180) ? -64 : 64);
	Xa = 64 / tan(alpha * M_PI / 180);
	a.x = pdata->coord->x + (pdata->coord->y - a.y) / tan(alpha * M_PI / 180);
	while (map->height > a.y / 64 && map->width > a.x / 64 && a.y >= 0 && a.x >= 0)
	{			
		if (map->map[(int)a.y / 64][(int)a.x / 64] == '1')		
			{
				//ft_putendl(ft_itoa(a.y / 64));//////////
				//ft_putendl(ft_itoa(a.x / 64));/////////
				return((ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y)));//;* cos(fabs(pdata->dir - alpha) * M_PI / 180)));
			}
		a.x = a.x + Xa;
		a.y = a.y + Ya;
	}
	return(-1);
	//return(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180));
}
