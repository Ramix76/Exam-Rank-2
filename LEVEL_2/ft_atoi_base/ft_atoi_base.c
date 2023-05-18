/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:28:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/17 16:51:07 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	return (0);
}

int	char_is_in_base(char c, int str_base)
{
	static char *base = "0123456789abcdef";
	static char *BASE = "0123456789ABCDEF";
	int					i;

	i = 0;
	while (base[i] && i < str_base)
	{
		if (c == base[i])
			return (1);
		if (c == BASE[i])
			return (1);
		i++;
	}
	return (0);
}

int	atoi_get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	return (10 + c - 'A');
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (char_is_in_base(str[i], str_base))
	{
		res = (res * str_base) + (atoi_get_value(str[i]));
		i++;
	}
	return (sign * res);
}

int	main()
{
	const char	*str = "1a";
	int	base = 16;
	int	result = ft_atoi_base(str, base);

	printf("Input: %s\n", str);
	printf("Base: %d\n", base);
	printf("Resultado: %d\n", result);
}
