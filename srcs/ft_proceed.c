/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:33:52 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:55:06 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>

static	void	ft_proceed_events(SDL_Event *event, int *quit, t_player *pdata)
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
			ft_move(pdata, sym, event->key.keysym.mod);
	}
}

static	void	ft_render(SDL_Renderer *r, t_map *map, t_player *pdata)
{
	SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
	SDL_RenderClear(r);////////////////////////////care for renderclear
	ft_draw_renderer(pdata, map, r);
	SDL_RenderPresent(r);
}

void			ft_proceed(t_screen *screen, t_map *map, t_player *pdata)
{
	int			quit;
	SDL_Event	event;

	quit = 0;
	while (!quit)
	{
		ft_render(screen->r, map, pdata);
		SDL_Delay(DELAY);
		while (SDL_PollEvent(&event))
			ft_proceed_events(&event, &quit, pdata);
	}
}
