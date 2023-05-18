/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:55:30 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/18 09:14:04 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	find_repeated(char c, char *str, int i)
{
	int	j;

	j = 0;
	while (str[j] && j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

void	ft_union(char **str)
{
	int	i;

	i = 0;
	while (str[1][i])
	{
		if (!find_repeated(str[1][i], str[1], i))
			write(1, &str[1][i], 1);
		i++;
	}
	i = 0;
	while (str[2][i])
	{
		if (!find_repeated(str[2][i], str[2],  i) && (!find_char(str[2][i], str[1])))
			write(1, &str[2][i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv);
	}
	write(1, "\n", 1);
	return (0);
}
