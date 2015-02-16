/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:09:31 by cheron            #+#    #+#             */
/*   Updated: 2015/02/16 12:32:29 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>
#include <libft.h>///////
static void	ft_move_forward(t_player *pdata, int speed)
{
	pdata->coord.x += (pdata->dir.x * speed) / 20;
	pdata->coord.y += (pdata->dir.y * speed) / 20;
}

static void	ft_move_backward(t_player *pdata, int speed)
{
	pdata->coord.x -= (pdata->dir.x * speed / 2) / 20;
	pdata->coord.y -= (pdata->dir.y * speed / 2) / 20;
}

void		ft_move(t_player *pdata, SDL_Keycode sym, SDL_Keymod mod)
{
	double	speed;

	speed = (mod == KMOD_LSHIFT ? SPEED * 3 : SPEED);
	if (sym == SDLK_DOWN)
		ft_move_backward(pdata, speed);
	else if (sym == SDLK_UP)
		ft_move_forward(pdata, speed);
}
