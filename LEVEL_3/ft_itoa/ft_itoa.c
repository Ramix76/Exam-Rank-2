/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:41:05 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/03 14:59:03 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	long int	n;
	int			len;
	char		*res;

	n = nbr;
	len = 0;
	if (n <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (res);
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
