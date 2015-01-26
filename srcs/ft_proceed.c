/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:33:52 by cheron            #+#    #+#             */
/*   Updated: 2015/01/26 16:28:37 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>
#include <libft.h>

void	ft_proceedEvents(SDL_Event *event, int *quit, t_pdata *pdata)
{
	int	val;

	while (SDL_PollEvent(event) != 0 )
	{
		val = (event->key.keysym.mod == KMOD_LSHIFT ? 3 : 1);
		if (event->window.event == SDL_WINDOWEVENT_CLOSE
			|| event->key.keysym.sym == SDLK_ESCAPE)
			*quit = 1;
		else if (event->key.keysym.sym == SDLK_RIGHT)
			pdata->dir = ((int)pdata->dir + val) % 360;
		else if (event->key.keysym.sym == SDLK_LEFT)
			pdata->dir = ((int)pdata->dir - val) % 360;
		else if (event->key.keysym.sym == SDLK_DOWN)
			pdata->coord->y += 1;
		else if (event->key.keysym.sym == SDLK_UP)
			pdata->coord->y -= 1;
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
//		SDL_Delay(3000);
		ft_proceedEvents(&event, &quit, pdata);
	}
}


