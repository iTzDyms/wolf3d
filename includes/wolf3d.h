/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:51 by cheron            #+#    #+#             */
/*   Updated: 2015/01/20 19:38:34 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define FOV 60
# define PLAYER_HEIGHT 32
# define PROJ_HEIGHT 200
# define PROJ_WIDTH 320
# define PLAYER_VIEW_DIR 45
# define W_TITLE "Wolf3D"

typedef	struct	s_map
{
	int			width;
	int			height;
	char		**map;
}				t_map;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef	struct	s_pdata
{
	t_coord		*coord;
	int			height;
	int			fov;
	int			dir;
}				t_pdata;

t_coord			*ft_alloccoord(void);
void			ft_freecoord(t_coord *coord);
t_map			*ft_allocmap(void);
void			ft_freemap(t_map *map);
t_pdata			*ft_allocpdata(void);
void			ft_freepdata(t_pdata *pdata);
void			ft_print_map(t_map *map);
void			set_player_pos(t_map *map, t_coord *pcoord);

#endif
