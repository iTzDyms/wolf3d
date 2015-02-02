/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:09:31 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 16:40:53 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>
#include <stdio.h>////////
static void	ft_move_forward(t_player *pdata, int speed)
{
	printf("\nmove forward\n");//////////
	pdata->coord.x += (pdata->dir.x * speed) / 10;
	pdata->coord.y += (pdata->dir.y * speed) / 10;
	printf("coord.x :: %f\ncoord.y :: %f\n", pdata->coord.x, pdata->coord.y);
}

static void	ft_move_backward(t_player *pdata, int speed)
{
	printf("\nmove back\n");/////////
	pdata->coord.x -= (pdata->dir.x * speed / 2) / 10;
	pdata->coord.y -= (pdata->dir.y * speed / 2) / 10;
	printf("coord.x :: %f\ncoord.y :: %f\n", pdata->coord.x, pdata->coord.y);
}

void		ft_move(t_player *pdata, SDL_Keycode sym, SDL_Keycode mod)
{
	double	speed;

	speed = (mod == SDLK_LSHIFT ? SPEED * 3 : SPEED );
	if (sym == SDLK_DOWN)
		ft_move_backward(pdata, speed);
	else if (sym == SDLK_UP)
		ft_move_forward(pdata, speed);
}
