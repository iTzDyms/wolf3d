/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:33:52 by cheron            #+#    #+#             */
/*   Updated: 2015/02/16 16:20:20 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>
#include <libft.h>////////////

static	void	ft_proceed_events(SDL_Event *event, int *quit, t_player *pdata,
								t_map *map)
{
	SDL_Keycode	sym;

	sym = event->key.keysym.sym;
	if (event->window.event == SDL_WINDOWEVENT_CLOSE || sym == SDLK_ESCAPE)
		*quit = 1;
	else if (event->type == SDL_KEYDOWN)
	{
		if (sym == SDLK_RIGHT || sym == SDLK_LEFT)
			ft_rotate(pdata, sym, event->key.keysym.mod);
		else if (sym == SDLK_DOWN || sym == SDLK_UP)
			ft_move(pdata, map, sym, event->key.keysym.mod);
	}
}

static	void	ft_apply_surf_to_render(SDL_Renderer *r, SDL_Surface *surface)
{
	SDL_Texture *frame;

	frame = SDL_CreateTextureFromSurface(r, surface);
	SDL_RenderCopy(r, frame, NULL, NULL);
	SDL_DestroyTexture(frame);		
}

void			ft_proceed(t_screen *screen, t_map *map, t_player *pdata)
{
	int			quit;
	SDL_Event	event;
	SDL_Surface	*surface;

	quit = 0;
	surface = ft_init_surface();
	while (!quit)
	{
		ft_draw_surface(map, pdata, surface);
		ft_apply_surf_to_render(screen->r, surface);
		SDL_RenderPresent(screen->r);
//		SDL_Delay(DELAY);
		while (SDL_PollEvent(&event))
			ft_proceed_events(&event, &quit, pdata, map);
	}
}
