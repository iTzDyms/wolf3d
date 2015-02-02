/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:18:10 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 17:42:37 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>
#include <stdio.h>////////
double	ft_distance(t_ray ray)
{
	double	dis;

//	printf("\ncalc dis :: \nmap.x :: %i\n coord.x :: %f\n step.x :: %i\n dir.x :: %f\n", ray.map.x, ray.coord.x, ray.step.x, ray.dir.x);////
//	printf("\ncalc dis :: \nmap.y :: %i\n coord.y :: %f\n step.y :: %i\n dir.y :: %f\n", ray.map.y, ray.coord.y, ray.step.y, ray.dir.y);////
	if (ray.where == 0)
		dis = fabs(((double)ray.map.x - ray.coord.x +
					(1.0 - (double)ray.step.x) / 2.0) / ray.dir.x);
	else
		dis = fabs(((double)ray.map.y - ray.coord.y +
					(1.0 - (double)ray.step.y) / 2.0) / ray.dir.y);
	return(dis);	
}
