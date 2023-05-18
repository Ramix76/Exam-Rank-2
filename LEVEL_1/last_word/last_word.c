/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:03:37 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/09 12:08:45 by framos-p         ###   ########.fr       */
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
			i++;
		i--;
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		while (!(str[i] == ' ' || str[i] == '\t'))
			i--;
		i++;
		while (!(str[i] == ' ' || str[i] == '\t') && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
