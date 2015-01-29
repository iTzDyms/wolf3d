/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:33:52 by cheron            #+#    #+#             */
/*   Updated: 2015/01/29 13:32:52 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>

void	ft_move(t_pdata *pdata, char *str)
{
	if (strcmp(str, "BACK") == 0)
	{
		pdata->coord->x -= (1 * cos(pdata->dir * M_PI / 180));
		pdata->coord->y -= (1 * cos((pdata->dir + 90)* M_PI / 180));
	}
	else
	{
		pdata->coord->x += (1 * cos(pdata->dir * M_PI / 180));
		pdata->coord->y += (1 * cos((pdata->dir + 90) * M_PI / 180));
	}
}
void	ft_proceedEvents(SDL_Event *event, int *quit, t_pdata *pdata)
{
	double	val;

	while (SDL_PollEvent(event) != 0 )
	{
		val = (event->key.keysym.mod == KMOD_LSHIFT ? 3 : 1);
		if (event->window.event == SDL_WINDOWEVENT_CLOSE
			|| event->key.keysym.sym == SDLK_ESCAPE)
			*quit = 1;
		else if (event->key.keysym.sym == SDLK_RIGHT)
			pdata->dir = ft_mod(pdata->dir, -val);
		else if (event->key.keysym.sym == SDLK_LEFT)
			pdata->dir = ft_mod(pdata->dir, val);
		else if (event->key.keysym.sym == SDLK_DOWN)
			ft_move(pdata, "BACK");
		else if (event->key.keysym.sym == SDLK_UP)
			ft_move(pdata, "FORWARD");
	}
}
void	ft_render(SDL_Renderer *r, t_map *map, t_pdata *pdata)
{
	SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
	SDL_RenderClear(r);
	ft_DrawRenderer(pdata, map, r);
	SDL_RenderPresent(r);
}

void	ft_proceed(t_screen *screen, t_map *map, t_pdata *pdata)
{
	int			quit;
	SDL_Event	event;

	quit = 0;
	while ( !quit )
	{
		ft_render(screen->r, map, pdata);
		SDL_Delay(DELAY);
		//SDL_Delay(3000);
		ft_proceedEvents(&event, &quit, pdata);
	}
}


