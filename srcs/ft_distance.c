/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:18:10 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:42:34 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>

double	ft_distance(t_ray ray)
{
	double	dis;

	if (ray.where == 0)
		dis = fabs(((double)ray.map.x - ray.coord.x +
					(1.0 - (double)ray.step.x) / 2.0) / ray.dir.x);
	else
		dis = fabs(((double)ray.map.y - ray.coord.y +
					(1.0 - (double)ray.step.y) / 2.0) / ray.dir.y);
	return (dis);
}
