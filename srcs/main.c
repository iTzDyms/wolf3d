/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:36:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 19:58:20 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <libft.h>
#include <wolf3d.h>

int	main(void)
{
	t_map		*map;
	t_player	pdata;
	t_screen	*screen;

	map = ft_allocmap();
	pdata = ft_get_player(map);
	screen = ft_allocscreen();
	ft_proceed(screen, map, &pdata);
	SDL_DestroyWindow(screen->win);
	SDL_Quit();
	ft_freemap(map);
	map = NULL;
	return (0);
}
