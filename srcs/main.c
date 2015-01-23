/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:36:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/23 14:47:40 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <libft.h>
#include <wolf3d.h>

int	main(void)
{
	t_map		*map;
	t_pdata		*pdata;
	t_screen	*screen;

	map = ft_allocmap();
	pdata = ft_allocpdata();
	set_player_pos(map, pdata->coord);
	screen = ft_allocscreen();
	ft_proceed(screen, map, pdata);
	SDL_DestroyWindow(screen->win);
	SDL_Quit();
	ft_freepdata(pdata);
	pdata = NULL;
	ft_freemap(map);
	map = NULL;
	return (0);
}
