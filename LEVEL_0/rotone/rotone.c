/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:05:50 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/04 11:11:01 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i;
		char	*str;

		i = 0;
		str = argv[1];
		while (str[i])
		{
			if ((str[i] >= 65 && str[i] <= 89) || (str[i] >= 97 && str[i] <= 121))
				str[i] = str[i] + 1;
			else if (str[i] == 90 || str[i] == 122)
				str[i] = str[i] - 25;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
