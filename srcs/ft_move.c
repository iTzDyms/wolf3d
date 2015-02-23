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
static void	ft_move_forward(t_player *pdata, t_map *map, int speed)
{
	double	nextx;
	double	nexty;
	int		signx;
	int		signy;

	signx = (pdata->dir.x > 0 ? 1 : -1);
	if (pdata->dir.x == 0 )
		signx = 0;
	signy = (pdata->dir.y > 0 ? 1 : -1);
	if (pdata->dir.y == 0 )
		signy = 0;
	nextx = pdata->coord.x + (pdata->dir.x * speed / 20);
	nexty = pdata->coord.y + (pdata->dir.y * speed / 20);
	if (hit_wall((int)(nextx + 0.1 * signx), (int)(nexty + 0.1 * signy), map))
		return ;
	pdata->coord.y = nexty;
	pdata->coord.x = nextx;
}

static void	ft_move_backward(t_player *pdata, t_map *map, int speed)
{
	double	nextx;
	double	nexty;
	int		signx;
	int		signy;

	signx = (pdata->dir.x > 0 ? 1 : -1);
	if (pdata->dir.x == 0 )
		signx = 0;
	signy = (pdata->dir.y > 0 ? 1 : -1);
	if (pdata->dir.y == 0 )
		signy = 0;
	nextx = pdata->coord.x - (pdata->dir.x * speed / 20);
	nexty = pdata->coord.y - (pdata->dir.y * speed / 20);
	if (hit_wall((int)(nextx - 0.1 * signx), (int)(nexty - 0.1 * signy), map))
		return ;	
	pdata->coord.x -= (pdata->dir.x * speed / 20);
	pdata->coord.y -= (pdata->dir.y * speed / 20);
}

void		ft_move(t_player *pdata, t_map *map, SDL_Keycode sym, SDL_Keymod mod)
{
	double	speed;

	speed = (mod == KMOD_LSHIFT ? SPEED * 3 : SPEED);
	if (sym == SDLK_DOWN)
		ft_move_backward(pdata, map, speed);
	else if (sym == SDLK_UP)
		ft_move_forward(pdata, map, speed);
}
