/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:31:28 by ehansman          #+#    #+#             */
/*   Updated: 2016/06/12 16:31:30 by ehansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	static t_data	gamedata;
	int				k;

	k = 1;
	get_player(&gamedata);
	while (k)
	{
		if (read_input(0, &gamedata))
		{
			k = scan_arr(&gamedata);
			reset_info(&gamedata);
		}
	}
	return (0);
}
