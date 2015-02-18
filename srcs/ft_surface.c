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

static void		ft_color_surface(SDL_Surface *surface, int width, int height,
								Uint32 pixel)
{
	Uint32	*pixels;
	int		i;
	int		j;

	pixels = (Uint32 *)surface->pixels;
	j = 0;
	SDL_LockSurface(surface);
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			pixels[j * width + i] = pixel;
			i++;
		}
		j++;
	}
	SDL_UnlockSurface(surface);
}

SDL_Surface		*ft_get_sky_surface(void)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, 
			PROJ_WIDTH,
			PROJ_HEIGHT / 2,
			32,
			0,
			0,
			0,
			0);
	if (surface == NULL)
		ft_fatal("surface creation failed");
	ft_color_surface(surface, PROJ_WIDTH, PROJ_HEIGHT / 2, (Uint32)0x38EBD5);
	return (surface);
}

SDL_Surface		*ft_get_floor_surface(void)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, 
			PROJ_WIDTH,
			PROJ_HEIGHT / 2,
			32,
			0,
			0,
			0,
			0);
	if (surface == NULL)
		ft_fatal("surface creation failed");	
	ft_color_surface(surface, PROJ_WIDTH, PROJ_HEIGHT / 2, (Uint32)0x66665D);
	return (surface);
}

SDL_Surface		*ft_get_wall_text(void)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, 
			PROJ_WIDTH,
			PROJ_HEIGHT / 2,
			32,
			0,
			0,
			0,
			0);
	if (surface == NULL)
		ft_fatal("surface creation failed");	
	return (surface);
}
