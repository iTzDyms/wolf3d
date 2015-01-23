/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createpdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:51:58 by cheron            #+#    #+#             */
/*   Updated: 2015/01/23 13:28:32 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

t_coord	*ft_alloccoord(void)
{
	return ((t_coord *)malloc(sizeof(t_coord)));
}

void	ft_freecoord(t_coord *coord)
{
	free(coord);
}
