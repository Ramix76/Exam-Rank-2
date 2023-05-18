/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:28:13 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/10 11:37:19 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		char	*str1;
		char	*str2;
		char	*str3;

		str1 = argv[1];
		str2 = argv[2];
		str3 = argv[3];
		if (str2[0] == '+')
			printf("%d", (atoi(str1) + atoi(str3)));
		if (str2[0] == '-')
			printf("%d", (atoi(str1) - atoi(str3)));
		if (str2[0] == '*')
			printf("%d", (atoi(str1) * atoi(str3)));
		if (str2[0] == '/')
			printf("%d", (atoi(str1) / atoi(str3)));
		if (str2[0] == '%')
			printf("%d", (atoi(str1) % atoi(str3)));
	}
	printf("\n");
	return (0);
}
