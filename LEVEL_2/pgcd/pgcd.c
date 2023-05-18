/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:31:04 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/09 10:47:45 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		unsigned int	a;
		unsigned int	b;
		unsigned int	pgcd;

		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > b)
			pgcd = a;
		else
			pgcd = b;
		while (pgcd > 0)
		{
			if (a % pgcd == 0 && b % pgcd == 0)
			{
				printf("%d", pgcd);
				break;
			}
			pgcd--;
		}
	}
	printf("\n");
	return (0);
}
