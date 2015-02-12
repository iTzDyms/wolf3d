/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_SDL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 14:05:20 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 15:26:06 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <stdlib.h>
#include <libft.h>

static	void	ft_sdl_init(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_putstr("Can't init SDL: ");
		ft_putendl(SDL_GetError());
		exit(1);
	}
}

SDL_Window		*ft_createwin(char *title, int height, int width)
{
	SDL_Window *win;

	ft_sdl_init();
	win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		ft_putstr("Can't set video mode: ");
		ft_putendl(SDL_GetError());
		exit(1);
	}
	return (win);
}
