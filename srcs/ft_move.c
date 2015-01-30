/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:09:31 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 19:10:05 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

void	ft_move(t_player *pdata, SDLKey sym, SDLMod mod)
{
		speed = (mod == SDLK_LSHIFT ? SPEED * 3 : SPEED );
			if (sym == SDLK_DOWN)
						ft_move_backward(pdata, speed);
				else if (sym == SDLK_UP)
							ft_move_upward(pdata, speed);
}

void	ft_move_forward(t_player *pdata, int speed)
{
		pdata->coord.x += pdata->coord.x * speed;
			pdata->coord.y += pdata->coord.y * speed;
}

void	ft_move_backward(t_player *pdata, int speed)
{
		pdata->coord.x -= pdata->coord.x * speed / 2;
			pdata->coord.y -= pdata->coord.y * speed / 2;
}
