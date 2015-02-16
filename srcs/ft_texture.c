/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:54:55 by cheron            #+#    #+#             */
/*   Updated: 2015/02/16 16:27:37 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

void	ft_init_textures(SDL_Renderer *r, t_text *text)
{
	text->sky = SDL_CreateTextureFromSurface(r, ft_get_sky_surface());	
	text->floor = SDL_CreateTextureFromSurface(r, ft_get_floor_surface());
}

void	ft_apply_floor_text(SDL_Renderer *r, t_player *pdata, t_text text)
{
	SDL_Rect	dstrect;

	dstrect.x = 0;
	dstrect.y = PROJ_HEIGHT / 2;
	dstrect.w = PROJ_WIDTH * pdata->dir.z;
	dstrect.h = PROJ_HEIGHT / 2;
	SDL_RenderCopy(r, text.floor, NULL, &dstrect);
}

void	ft_apply_sky_text(SDL_Renderer *r, t_player *pdata, t_text text)
{
	SDL_Rect	dstrect;

	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = PROJ_WIDTH * pdata->dir.z;
	dstrect.h = PROJ_HEIGHT / 2;
	SDL_RenderCopy(r, text.sky, NULL, &dstrect);
}

