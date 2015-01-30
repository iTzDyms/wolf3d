/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:56:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 17:01:27 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>

#include <libft.h>
#include <stdio.h>
double	ft_fisheye(double dir, double alpha)
{
	double	res;

	return(1);
	res = cos(((dir - alpha) * M_PI / 180));
	if ( res == 0 )
		res = 0.000001;
	//printf("%f\n",res);
	return(res);
}
double	ft_distance(double x1, double y1, double x2, double y2)
{
	double pow1;
	double pow2;

	pow1 = pow((x1 - x2), 2);
	pow2 = pow((y1 - y2), 2); 
	return((sqrt(pow1+pow2)));
}

double	inter_vertical(t_map *map, t_pdata *pdata, double alpha)
{
	t_coord	a;
	double	Ya;
	double	Xa;

	//ft_putendl("enter verti");
	if (alpha == 270 || alpha == 90)
		return(-1);
	a.x = floor(pdata->coord->x / 64) * 64;
	a.x = ((alpha > 270 || alpha < 90) ? a.x + 64 : a.x -1);
//	alpha = ((alpha > 270 || alpha < 90) ? alpha : alpha );
	Xa = ((alpha > 270 || alpha < 90) ? +64 : -64);
	Ya = (int)(64 * tan(alpha * M_PI / 180));
	if ( alpha > 270 || alpha < 90)
		Ya = -Ya;
	a.y = (int)(pdata->coord->y + (pdata->coord->x - a.x) * tan(alpha * M_PI / 180));
	//ft_putendl("before");
	//ft_putendl(ft_itoa(map->height));
	//ft_putendl(ft_itoa(map->width));
	//ft_putendl(ft_itoa(a.y / 64));
	//ft_putendl(ft_itoa(a.x / 64));
	//ft_putendl(ft_itoa(map->map[a.y/64][a.x/64]));
//	ft_putstr("Yavvv ==> ");
//	ft_putendl(ft_itoa(Ya));
//	ft_putstr("Xavvv ==> ");
//	ft_putendl(ft_itoa(Xa));
	while ( map->height > a.y / 64 && map->width > a.x / 64 && a.y >= 0 && a.x >= 0)
	{	
	//	ft_putendl(ft_itoa(Xa));
	//	ft_putendl(ft_itoa(Ya));
	
	//ft_putendl("boucle");	
	//	ft_putstr("p.y ==> ");
	///	ft_putendl(ft_itoa(pdata->coord->y));
	//	ft_putstr("p.x ==> ");
	//	ft_putendl(ft_itoa(pdata->coord->x));
	//	ft_putstr("a.y ==> ");
	//	ft_putstr(ft_itoa(a.y));
	//	ft_putstr("  ==> ");
	//	ft_putendl(ft_itoa(a.y / 64));
	//	ft_putstr("a.x ==> ");
	//	ft_putstr(ft_itoa(a.x));
	//	ft_putstr("  ==> ");
	//	ft_putendl(ft_itoa(a.x / 64));
	//	ft_putstr("Ya ==> ");
	//	ft_putendl(ft_itoa(Ya));
	//	ft_putstr("Xa ==> ");
	//	ft_putendl(ft_itoa(Xa));	
	//	ft_putendl("boucle");		
		if (map->map[(int)a.y / 64][(int)a.x / 64] == '1')
		{
			//	ft_putstr("{\n	px ==> ");
			//	ft_putendl(ft_itoa(pdata->coord->x));
			//	ft_putstr("	py ==> ");
			//	ft_putendl(ft_itoa(pdata->coord->y));
			//	ft_putstr("	a.x ==> ");
			//	ft_putendl(ft_itoa(a.x));
			//	ft_putstr("	a.y ==> ");
			//	ft_putendl(ft_itoa(a.y));
				//ft_putendl(ft_itoa(a.y / 64));//////////
				//ft_putendl(ft_itoa(a.x / 64));/////////i
			//	ft_putstr("	dist : ");
			//	ft_putendl(ft_itoa(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180)));
			//	ft_putendl("}");
			//ft_putendl(ft_itoa(a.y / 64));//////////
			//ft_putendl(ft_itoa(a.x / 64));/////////
			return(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * ft_fisheye(pdata->dir, alpha)); //* cos(fmod(pdata->dir - alpha + 360, 360) * M_PI / 180));
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

	//ft_putendl("enter hori");
	if (alpha == 0 || alpha == 180)
		return(-1);
	a.y = floor(pdata->coord->y / 64) * 64;
	//ft_putendl(ft_itoa(a.y));
	a.y = ((alpha < 180) ? a.y - 1 : a.y + 64);
	Ya = ((alpha < 180) ? -64 : 64);
	Xa = (int)(64 / tan(alpha * M_PI / 180));
	if (alpha > 180)
		Xa = -Xa;
	a.x = (int)(pdata->coord->x + (pdata->coord->y - a.y) / tan(alpha * M_PI / 180));
	//	ft_putstr("Yahhh ==> ");
//	ft_putendl(ft_itoa(Ya));
//	ft_putstr("Xahhh ==> ");
//	ft_putendl(ft_itoa(Xa));
	
	//	ft_putstr("p.y ==> ");
	//	ft_putendl(ft_itoa(pdata->coord->y));
	//	ft_putstr("p.x ==> ");
	//	ft_putendl(ft_itoa(pdata->coord->x));
	//	ft_putstr("a.y ==> ");
	//	ft_putstr(ft_itoa(a.y));
	//	ft_putstr("  ==> ");
	//	ft_putendl(ft_itoa(a.y / 64));
	//	ft_putstr("a.x ==> ");
	//	ft_putstr(ft_itoa(a.x));
	//	ft_putstr("  ==> ");
	//	ft_putendl(ft_itoa(a.x / 64));
	//	ft_putstr("Ya ==> ");
	//	ft_putendl(ft_itoa(Ya));
	//	ft_putstr("Xa ==> ");
	//	ft_putendl(ft_itoa(Xa));	

	while (map->height > a.y / 64 && map->width > a.x / 64 && a.y >= 0 && a.x >= 0)
	{	
	//	ft_putendl("boucle");	
	//	ft_putstr("a.y ==> ");
	//	ft_putstr(ft_itoa(a.y));
	//	ft_putstr("  ==> ");
	//	ft_putendl(ft_itoa(a.y / 64));
	//	ft_putstr("a.x ==> ");
	//	ft_putstr(ft_itoa(a.x));
	//	ft_putstr("  ==> ");
	//	ft_putendl(ft_itoa(a.x / 64));
	//	ft_putstr("Ya ==> ");
	//	ft_putendl(ft_itoa(Ya));
	//	ft_putstr("Xa ==> ");
	///	ft_putendl(ft_itoa(Xa));
		if (map->map[(int)a.y / 64][(int)a.x / 64] == '1')		
			{
	//			ft_putstr("{\n	px ==> ");
	//			ft_putendl(ft_itoa(pdata->coord->x));
	//			ft_putstr("	py ==> ");
	//			ft_putendl(ft_itoa(pdata->coord->y));
	//			ft_putstr("	a.x ==> ");
	//			ft_putendl(ft_itoa(a.x));
	//			ft_putstr("	a.y ==> ");
	//			ft_putendl(ft_itoa(a.y));
	//			//ft_putendl(ft_itoa(a.y / 64));//////////
				//ft_putendl(ft_itoa(a.x / 64));/////////i
	//			ft_putstr("	dist : ");
	//			ft_putendl(ft_itoa(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180)));
	//			ft_putendl("}");
				return(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * ft_fisheye(pdata->dir, alpha));// * cos(fmod(pdata->dir - alpha + 360, 360) * M_PI / 180));
			}
		a.x = a.x + Xa;
		a.y = a.y + Ya;
	}
	return(-1);
	//return(ft_distance(pdata->coord->x, pdata->coord->y, a.x, a.y) * cos(fabs(pdata->dir - alpha) * M_PI / 180));
}
