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

static	void	ft_render(SDL_Renderer *r, t_map *map, t_player *pdata,
	   t_text text)
{
//	SDL_Rect	rect;

//	rect.x = 0;
//	rect.y = PROJ_HEIGHT / 2;
//	rect.w = PROJ_WIDTH;
//	rect.h = PROJ_HEIGHT / 2;
//	SDL_SetRenderDrawColor(r, 0, 255, 255, 255);
//	ft_draw_rectangle(r, 0, PROJ_WIDTH - 1, 0, PROJ_HEIGHT / 2 - 1);
//	SDL_RenderClear(r);
//	SDL_SetRenderDrawColor(r, 81, 86, 90, 255);
//	ft_draw_rectangle(r, 0, PROJ_WIDTH - 1, PROJ_HEIGHT / 2 , PROJ_HEIGHT - 1);	
//	SDL_RenderFillRect(r, &rect);
	ft_apply_sky_text(r, pdata, text);
	ft_apply_floor_text(r, pdata, text);
//	ft_apply_wall_text(r, pdata);
	ft_draw_renderer(pdata, map, r);
	SDL_RenderPresent(r);
}

void			ft_proceed(t_screen *screen, t_map *map, t_player *pdata)
{
	int			quit;
	SDL_Event	event;
	t_text		text;

	quit = 0;
	ft_init_textures(screen->r, &text);
	while (!quit)
	{
		ft_render(screen->r, map, pdata, text);
		SDL_Delay(DELAY);
		while (SDL_PollEvent(&event))
			ft_proceed_events(&event, &quit, pdata);
	}
}
