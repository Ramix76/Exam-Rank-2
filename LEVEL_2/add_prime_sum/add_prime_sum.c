/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:41:09 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/03 13:01:47 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	fprime(int nbr)
{
	int	check;

	if (nbr <= 1)
		return (0);
	check = 2;
	while (check < nbr)
	{
		if (nbr % check == 0)
			return (0);
		check++;
	}
	return (1);
}

void	putnbr(int nbr)
{
	char	*base = "0123456789";

	if (nbr > 9)
		putnbr(nbr / 10);
	write(1, &base[nbr % 10], 1);
}

int	add_prime_sum(int nbr)
{
	int	i;
	int	sum;

	sum = 0;
	if (nbr <= 1)
		return (0);
	i = 2;
	while (i <= nbr)
	{
		if (fprime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		putnbr(add_prime_sum(ft_atoi(argv[1])));
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
