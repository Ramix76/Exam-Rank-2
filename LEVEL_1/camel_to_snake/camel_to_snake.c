/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/11 15:08:51 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i;
		char	*str;

		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				write(1, "_", 1);
				str[i] = str[i] + 32;
			}
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
