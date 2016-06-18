/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:30:43 by ehansman          #+#    #+#             */
/*   Updated: 2016/06/12 16:39:01 by ehansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_free(t_grid *grid)
{
	int		k;

	k = 0;
	while (k < grid->y)
	{
		free(grid->g[k]);
		k++;
	}
	free(grid->g);
	return (1);
}

int		reset_info(t_data *info)
{
	ft_free(&info->map);
	ft_free(&info->piece);
	info->map.y = 0;
	info->map.x = 0;
	info->piece.y = 0;
	info->piece.x = 0;
	return (1);
}
