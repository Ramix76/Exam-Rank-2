/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:37:56 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/10 12:05:21 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	return (0);
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] >= 97 && str[i] <= 122))
			str[i] = str[i] - 32;
		else if ((str[i] >= 97 && str[i] <= 122) && is_space(str[i - 1]))
			str[i] = str[i] - 32;
		else if ((str[i] >= 97 && str[i] <= 122) && is_space(str[i - 1]) && is_space(str[i + 1]))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argc > 2)
	{
		int	i;
		i = 1;
		while (i < argc)
		{
			if (i == argc)
			{
				str_capitalizer(argv[i]);
				break;
			}
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else if (argc == 2)
	{
		str_capitalizer(argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}
