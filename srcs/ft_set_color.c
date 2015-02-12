/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:07:21 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:07:57 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

void	ft_set_draw_color(SDL_Renderer *r, t_ray ray)
{
	if (ray.dir.y > 0 && ray.where == 1)
		SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
	else if (ray.dir.y <= 0 && ray.where == 1)
		SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
	else if (ray.dir.x <= 0 && ray.where == 0)
		SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
	else
		SDL_SetRenderDrawColor(r, 0, 255, 255, 255);
}
