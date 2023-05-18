/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:31:12 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/03 14:40:33 by framos-p         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	(void)argv;

	if (argc > 1)
	{
		int	i;

		i = 1;
		while (i < argc - 1)
			i++;
		putnbr(i);
	}
	else
		putnbr(0);
	write(1, "\n", 1);
	return (0);
}
