/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:36:03 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 07:59:30 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	t;

	t = (unsigned char)c;
	if (t >= '0' && t <= '9')
		return (1);
	else
		return (0);
}