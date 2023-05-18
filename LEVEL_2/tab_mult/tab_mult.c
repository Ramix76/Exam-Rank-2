/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:01:02 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/15 16:11:38 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

void	putnbr(int nbr)
{
	char *base = "0123456789";

	if (nbr > 9)
		putnbr(nbr / 10);
	write(1, &base[nbr % 10], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i;
		int	num = ft_atoi(argv[1]);
		i = 0;
		while (i <= 9)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(num);
			write(1, " = ", 3);
			putnbr(i * num);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
