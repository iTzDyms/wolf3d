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

SDL_Surface		*ft_get_sky_surface(void)
{
	SDL_Surface	*surface;
	Uint32		custom;
	Uint32		*pixels;

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
	custom = 0x38EBD5;
	SDL_LockSurface(surface);
	//Convert the pixels to 32 bit
	pixels = (Uint32 *)surface->pixels;
	pixels[0] = custom;
//	ft_color_surface(surface, PROJ_WIDTH, PROJ_HEIGHT / 2, );
	SDL_UnlockSurface(surface);
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
	return (surface);
}
