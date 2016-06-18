/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:33:21 by ehansman          #+#    #+#             */
/*   Updated: 2016/06/12 16:33:23 by ehansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		scan_imm_foe(t_data *info, t_coord pos)
{
	t_coord		counts;
	int			weight;

	weight = 0;
	counts.y = 0;
	counts.x = -1;
	while (++counts.x < 3)
		if ((ON_MAP03) && (ft_is_foe(info->player, M_POS01)))
			weight += 10;
	counts.x = -1;
	if (ON_MAP01 && ft_is_foe(info->player, info->map.g[pos.y][pos.x - 1]))
		weight += 10;
	counts.x = 1;
	if (ON_MAP01 && ft_is_foe(info->player, info->map.g[pos.y][pos.x + 1]))
		weight += 10;
	counts.x = -1;
	while (++counts.x < 3)
	{
		if (ON_MAP03)
			if (ft_is_foe(info->player, M_POS01))
				weight += 10;
		counts.x++;
	}
	return (weight);
}

int		weight_option(t_data *info, t_coord pos,
			int *best_weight, t_coord *best)
{
	t_coord		counts;
	int			weight;
	t_coord		overlap;

	weight = 0;
	counts.y = pos.y;
	overlap = find_overlap(info, pos);
	weight = ft_est_angle(NE_FOE, overlap, FUR_01);
	while (counts.y < info->piece.y + pos.y)
	{
		counts.x = pos.x;
		while (counts.x < info->piece.x + pos.x)
		{
			if (ON_MAP && ON_PIE && PIE_POS == '*')
				weight += scan_imm_foe(info, counts);
			counts.x++;
		}
		counts.y++;
	}
	if ((weight > *best_weight) || CLOSER)
	{
		*best_weight = weight;
		*best = pos;
	}
	return (weight);
}
