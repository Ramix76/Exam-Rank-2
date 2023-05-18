/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:36:19 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/08 11:39:46 by framos-p         ###   ########.fr       */
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
			if ((str[i] >= 65 && str[i] <= 77) || (str[i] >= 97 && str[i] <= 109))
				str[i] = str[i] + 13;
			else if ((str[i] >= 78 && str[i] <= 90) || (str[i] >= 110 && str[i] <= 122))
				str[i] = str[i] - 13;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
