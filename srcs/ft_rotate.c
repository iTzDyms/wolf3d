/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:10:40 by cheron            #+#    #+#             */
/*   Updated: 2015/02/16 12:32:42 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>

static void	ft_rot_right(t_player *pdata, double speed)
{
	double	odirx;
	double	ocamx;
	double	rot;

	rot = ROT * speed / 20;
	odirx = pdata->dir.x;
	ocamx = pdata->cam.x;
	pdata->dir.x = pdata->dir.x * cos(rot) - pdata->dir.y * sin(rot);
	pdata->dir.y = odirx * sin(rot) + pdata->dir.y * cos(rot);
	pdata->cam.x = pdata->cam.x * cos(rot) - pdata->cam.y * sin(rot);
	pdata->cam.y = ocamx * sin(rot) + pdata->cam.y * cos(rot);
}

static void	ft_rot_left(t_player *pdata, double speed)
{
	double	odirx;
	double	ocamx;
	double	rot;

	rot = ROT * speed / 20;
	odirx = pdata->dir.x;
	ocamx = pdata->cam.x;
	pdata->dir.x = pdata->dir.x * cos(-rot) - pdata->dir.y * sin(-rot);
	pdata->dir.y = odirx * sin(-rot) + pdata->dir.y * cos(-rot);
	pdata->cam.x = pdata->cam.x * cos(-rot) - pdata->cam.y * sin(-rot);
	pdata->cam.y = ocamx * sin(-rot) + pdata->cam.y * cos(-rot);
}

void		ft_rotate(t_player *pdata, SDL_Keycode sym, SDL_Keymod mod)
{
	double	speed;

	speed = (mod == KMOD_LSHIFT ? SPEED * 3 : SPEED);
	if (sym == SDLK_LEFT)
		ft_rot_left(pdata, speed);
	else if (sym == SDLK_RIGHT)
		ft_rot_right(pdata, speed);
}
