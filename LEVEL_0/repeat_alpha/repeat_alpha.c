/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:53:29 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/05 11:02:43 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i;
		int	j;
		int	k;
		char	*str;

		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				j = 0;
				while (j < str[i] - 64)
				{
					write(1, &str[i], 1);
					j++;
				}
			}
			else if (str[i] >= 97 && str[i] <= 122)
			{
				k = 0;
				while (k < str[i] - 96)
				{
					write(1, &str[i], 1);
					k++;
				}
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
