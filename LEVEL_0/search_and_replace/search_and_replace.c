/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:33:39 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/10 14:39:01 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int	i;
		char	*str1;
		char	*str2;
		char	*str3;

		i = 0;
		str1 = argv[1];
		str2 = argv[2];
		str3 = argv[3];
		while (str1[i] && str2[1] == '\0' && str3[1] == '\0')
		{
			if (str1[i] == str2[0])
				str1[i] = str3[0];
			write(1, &str1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
