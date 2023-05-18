/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:30:40 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/04 11:39:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	puthex(int nbr)
{
	char	*base = "0123456789abcdef";

	if (nbr > 16)
		puthex(nbr / 16);
	write(1, &base[nbr % 16], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		puthex(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
