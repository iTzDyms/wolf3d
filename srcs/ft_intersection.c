/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:56:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/20 19:45:50 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>

int		inter_vertical(t_map *map, tpdata *pdata)
{
	return( vertical inter distance );
}

int		inter_horizontal(tmap *map, tpdata *pdata, alpha)
{
	int	ay;
	int	ax;

	ay = round(pdata->y / 64) * 64;
	ay = ((pdata->dir > 0 && pdaa->dir < 180) ? ay - 1 : ay + 64);
	ax = pdata->x + (pdata->y - ay) / (int)tan((double)alpha);
	return( horizontale inter distance );
}
