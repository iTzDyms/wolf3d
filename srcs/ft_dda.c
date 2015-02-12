/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:54:25 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:42:14 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static	void	ft_incx(t_ray *ray)
{
	ray->side.x += ray->delta.x;
	ray->map.x += ray->step.x;
	ray->where = 0;
}

static	void	ft_incy(t_ray *ray)
{
	ray->side.y += ray->delta.y;
	ray->map.y += ray->step.y;
	ray->where = 1;
}

t_ray			ft_dda(t_ray ray, t_map *map)
{
	while (!hit_wall(ray.map.x, ray.map.y, map))
	{
		if (ray.side.x < ray.side.y)
			ft_incx(&ray);
		else
			ft_incy(&ray);
	}
	return (ray);
}
