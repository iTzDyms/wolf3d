/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:51 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 14:53:43 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL.h>

# define FOV (double)60.0
# define PLAYER_HEIGHT 32
# define PROJ_HEIGHT 768
# define PROJ_WIDTH 1366
# define PLAYER_VIEW_DIR (double)0.0
# define W_TITLE "Wolf3D"
# define DELAY 1000 / 60
# define DELTA_ALPHA FOV / (double)PROJ_WIDTH

typedef	struct		s_screen
{
	SDL_Window		*win;
	SDL_Renderer	*r;	
}					t_screen;

typedef	struct		s_map
{
	int				width;
	int				height;
	char			**map;
}					t_map;

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef	struct		s_pdata
{
	t_coord			*coord;
//	int				height;
	int				fov;
//	int				projdist;
//	int				wallh;
	double			dir;
}					t_pdata;

t_screen			*ft_allocscreen(void);
void				ft_freescreen(t_screen *screen);
t_coord				*ft_alloccoord(void);
void				ft_freecoord(t_coord *coord);
t_map				*ft_allocmap(void);
void				ft_freemap(t_map *map);
t_pdata				*ft_allocpdata(void);
void				ft_freepdata(t_pdata *pdata);
void				ft_print_map(t_map *map);
void				set_player_pos(t_map *map, t_coord *pcoord);
double				inter_vertical(t_map *map, t_pdata *pdata, double alpha);
double				inter_horizontal(t_map *map, t_pdata *pdata, double alpha);
SDL_Window			*ft_createwin(char *title, int height, int width);
void				ft_proceed(t_screen *screen, t_map *map, t_pdata *pdata);
void				ft_DrawRenderer(t_pdata *pdat, t_map *map, SDL_Renderer *r);
double				ft_mod(double res);

#endif
