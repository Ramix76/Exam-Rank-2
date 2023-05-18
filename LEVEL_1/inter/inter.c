/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:33:06 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/18 09:14:11 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_repeated(char *str, int i)
{
	int	j;

	j = 0;
	while (str[j] && j < i)
	{
		if (str[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

void	inter(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[1][i])
	{
		j = 0;
		while (str[2][j])
		{
			if (str[1][i] == str[2][j] && !find_repeated(str[1], i))
			{
				write(1, &str[1][i], 1);
				break;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv);
	}
	write(1, "\n", 1);
	return (0);
}
