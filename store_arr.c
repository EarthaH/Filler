/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:30:02 by ehansman          #+#    #+#             */
/*   Updated: 2016/06/12 16:33:10 by ehansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_malloc_arr(t_grid *grid)
{
	int			k;

	k = 0;
	grid->g = (char **)ft_strnew((grid->y + 1) * sizeof(char *));
	while (k < grid->y)
	{
		grid->g[k] = (char *)ft_strnew((grid->x + 30) * sizeof(char));
		k++;
	}
	return (1);
}

int		store_arr(t_grid *grid, char *line, int cur_line)
{
	int			k;
	static int	didmalloc;

	k = 0;
	if (cur_line == 0)
	{
		didmalloc++;
		ft_malloc_arr(grid);
	}
	while (k < grid->x)
	{
		grid->g[cur_line][k] = line[k];
		k++;
	}
	return (1);
}
