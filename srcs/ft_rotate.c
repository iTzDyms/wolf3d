/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:10:40 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 19:47:45 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

static void	ft_rotate_left(t_player *pdata, int speed)
{
	double	coordx;
	double	camx;
	double	rot;

	rot = ROT * speed;
	coordx = pdata->coord.x;
	camx = pdata->cam.x;
	pdata->coord.x = pdata->coord.x * cos(-rot) - pdata->coord.y * sin(-rot);
	pdata->coord.y = coordx * sin(-rot) + pdata->coord.y * cos(-rot);
	pdata->cam.x = pdata->cam.x * cos(-rot) - pdata->cam.y * sin(-rot);
	pdata->cam.y = camx * sin(-rot) + pdata->cam.y * cos(-rot);
}

static void	ft_rot_right(t_player *pdata, int speed)
{
	double	coordx;
	double	camx;
	double	rot;

	rot = ROT * speed;
	coordx = pdata->coord.x;
	camx = pdata->cam.x;
	pdata->coord.x = pdata->coord.x * cos(rot) - pdata->coord.y * sin(rot);
	pdata->coord.y = coordx * sin(rot) + pdata->coord.y * cos(rot);
	pdata->cam.x = pdata->cam.x * cos(rot) - pdata->cam.y * sin(rot);
	pdata->cam.y = camx * sin(rot) + pdata->cam.y * cos(rot);
}

void	ft_rotate(t_player *pdata, SDLKey sym, SDLMod mod)
{
	speed = (mod == SDLK_LSHIFT ? SPEED * 3 : SPEED );
	if (sym == SDLK_LEFT && sym.bidule == KEY_RELEASE)
		ft_rotate_left(pdata, speed);
	else if (sym == SDLK_RIGHT)
		ft_rotate_right(pdata, speed);
}
