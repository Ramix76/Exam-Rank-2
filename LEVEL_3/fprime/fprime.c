/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:29:39 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/05 11:34:00 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fprime(int	nbr)
{
	int	check;

	if (nbr <= 1)
		return ;
	check = 2;
	while (check <= nbr)
	{
		if (nbr % check == 0)
		{
			printf("%d", check);
			if (nbr != check)
				printf("*");
			nbr /= check;
			check--;
		}
		check++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
