/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:10:57 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:45:10 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

t_screen		*ft_allocscreen(void)
{
	t_screen	*screen;

	if (!(screen = (t_screen *)malloc(sizeof(t_screen))))
		return (NULL);
	screen->win = NULL;
	screen->r = NULL;
	screen->win = ft_createwin(W_TITLE, PROJ_HEIGHT, PROJ_WIDTH);
	screen->r = SDL_CreateRenderer(screen->win, -1, 0);
	return (screen);
}

void			ft_freescreen(t_screen *screen)
{
	free(screen);
}
