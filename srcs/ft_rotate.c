/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:10:40 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 16:45:17 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>
#include <stdio.h>////////
static void	ft_rot_left(t_player *pdata, double speed)
{
	double	dirx;
	double	camx;
	double	rot;

	printf("\nrot left\n");
	rot = ROT * speed;
	dirx = pdata->dir.x;
	camx = pdata->cam.x;
	pdata->dir.x = pdata->dir.x * cos(-rot) - pdata->dir.y * sin(-rot);
	pdata->dir.y = dirx * sin(-rot) + pdata->dir.y * cos(-rot);
	pdata->cam.x = pdata->cam.x * cos(-rot) - pdata->cam.y * sin(-rot);
	pdata->cam.y = camx * sin(-rot) + pdata->cam.y * cos(-rot);
}

static void	ft_rot_right(t_player *pdata, double speed)
{
	double	dirx;
	double	camx;
	double	rot;

	printf("\nrot right\n");
	rot = ROT * speed;
	dirx = pdata->dir.x;
	camx = pdata->cam.x;
	pdata->dir.x = pdata->dir.x * cos(rot) - pdata->dir.y * sin(rot);
	pdata->dir.y = dirx * sin(rot) + pdata->dir.y * cos(rot);
	pdata->cam.x = pdata->cam.x * cos(rot) - pdata->cam.y * sin(rot);
	pdata->cam.y = camx * sin(rot) + pdata->cam.y * cos(rot);
}

void	ft_rotate(t_player *pdata, SDL_Keycode sym, SDL_Keycode mod)
{
	double	speed;

	speed = (mod == SDLK_LSHIFT ? SPEED * 3 : SPEED );
	if (sym == SDLK_LEFT)
		ft_rot_left(pdata, speed);
	else if (sym == SDLK_RIGHT)
		ft_rot_right(pdata, speed);
	printf("dir.x :: %f\ndir.y :: %f\ncam.x :: %f\ncam.y :: %f\n", pdata->dir.x, pdata->dir.y, pdata->cam.x, pdata->cam.y);
}
