/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surface.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:57:29 by cheron            #+#    #+#             */
/*   Updated: 2015/02/16 18:24:01 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>
#include <libft.h>
#include <stdio.h>

SDL_Surface		*ft_init_surface(void)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, 
			PROJ_WIDTH,
			PROJ_HEIGHT,
			32,
			0,
			0,
			0,
			0);
	if (surface == NULL)
		ft_fatal("surface creation failed");
	return (surface);
}

void		ft_surface_draw_verline(SDL_Surface *surface, int col,
									int start, int end, Uint32 pixel)
{
	Uint32	*pixels;

	pixels = (Uint32 *)surface->pixels;
	while (start < end)
	{
		pixels[(start * PROJ_WIDTH) + col] = pixel;
		start++;
	}
}


void		ft_surface_draw_rect(SDL_Surface *surface, t_pos pos,
								int width, int height, Uint32 pixel)
{
	int		i;
	int		end;

	end = pos.y + height;
	i = 0;
	while (i < width )
	{
		ft_surface_draw_verline(surface, pos.x + i, pos.y, end, pixel);
		i++;
	}
}
