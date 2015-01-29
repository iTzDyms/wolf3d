/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:43:57 by cheron            #+#    #+#             */
/*   Updated: 2015/01/27 16:31:10 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ft_mod(double a, double b)
{
	double	res;

	res = a + b;
	if (res < 0)
	{
		res = res + 360;
	}
	else
		res = fmod(res, 360);
	return(res);
	//return (fmod(a + b + 360));
}
