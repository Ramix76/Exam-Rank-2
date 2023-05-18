/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:33:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/09 12:43:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int nbr)
{
	char	*base = "0123456789";

	if (nbr > 9)
		putnbr(nbr / 10);
	write(1, &base[nbr % 10], 1);
}

void	fizzbuzz(int nbr)
{
	int	i;

	if (nbr == 0)
		return ;
	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

int	main()
{
	fizzbuzz(100);
	return (0);
}
