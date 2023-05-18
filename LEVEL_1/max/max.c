/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:11:16 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/04 11:21:19 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int	*tab, unsigned int len)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = tab[i];
	while (i < len - 1)
	{
		if (res < tab[i + 1])
			res = tab[i + 1];
		i++;
	}
	return (res);
}
