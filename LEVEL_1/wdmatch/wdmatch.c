/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:37:09 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/11 16:56:27 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	i;
		int	j;
		int	k;
		int	len;
		char *str1;
		char *str2;

		str1 = argv[1];
		str2 = argv[2];
		len = ft_strlen(str1);
		i = 0;
		k = 0;
		j = 0;
		while (str1[i])
		{
			while (str2[j])
			{
				if (str1[i] == str2[j])
				{
					k++;
					break;
				}
				j++;
			}
			i++;
		}
		if (k == len)
			putstr(str1);
	}
	write(1, "\n", 1);
	return (0);
}
