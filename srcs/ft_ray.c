/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:02:57 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:44:17 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>

static	void	ft_get_step_side(t_ray *ray)
{
	ray->step.x = (ray->dir.x < 0 ? -1 : 1);
	ray->side.x = (ray->dir.x < 0 ?
			(ray->coord.x - (double)ray->map.x) * ray->delta.x :
			((double)ray->map.x + 1.0 - ray->coord.x) * ray->delta.x);
	ray->step.y = (ray->dir.y < 0 ? -1 : 1);
	ray->side.y = (ray->dir.y < 0 ?
			(ray->coord.y - (double)ray->map.y) * ray->delta.y :
			((double)ray->map.y + 1.0 - ray->coord.y) * ray->delta.y);
}

t_ray			ft_get_ray(t_player *pdata, int i)
{
	t_ray		ray;
	double		camerax;

	camerax = 2 * (double)i / (double)PROJ_WIDTH - 1;
	ray.coord.x = pdata->coord.x;
	ray.coord.y = pdata->coord.y;
	ray.dir.x = pdata->dir.x + pdata->cam.x * camerax;
	ray.dir.y = pdata->dir.y + pdata->cam.y * camerax;
	ray.map.x = (int)pdata->coord.x;
	ray.map.y = (int)pdata->coord.y;
	ray.delta.x = sqrt(1 + (ray.dir.y * ray.dir.y) / (ray.dir.x * ray.dir.x));
	ray.delta.y = sqrt(1 + (ray.dir.x * ray.dir.x) / (ray.dir.y * ray.dir.y));
	ft_get_step_side(&ray);
	return (ray);
}
