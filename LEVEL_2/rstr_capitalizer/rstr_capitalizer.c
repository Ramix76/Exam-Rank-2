/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:24:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/03 17:26:07 by framos-p         ###   ########.fr       */
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

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if 	(str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122) && (is_space(str[i + 1]) || str[i + 1] == '\0'))
			str[i] = str[i] - 32;
		else if ((str[i] >= 97 && str[i] <= 122) && (is_space(str[i - 1]) && (is_space(str[i + 1]) || i == 0)))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		int	i;

		i = 1;
		while (i < argc - 1)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
		if (i == argc - 1)
			rstr_capitalizer(argv[i]);
	}
	if (argc == 2)
		rstr_capitalizer(argv[1]);
	write(1, "\n", 1);
	return (0);
}
