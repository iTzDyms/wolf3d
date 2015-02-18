/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:07:21 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 17:38:07 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

Uint32	ft_get_draw_color(t_ray ray)
{
	Uint32	color;

	if (ray.dir.y > 0 && ray.where == 1)
		color = 0xCC6600;
	else if (ray.dir.y <= 0 && ray.where == 1)
		color = 0x6600FF;
	else if (ray.dir.x <= 0 && ray.where == 0)
		color = 0x5CBD5C;	
	else
		color = 0xFF6600;
	return (color);
}
