/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:37:41 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:51 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i > 0 && !is_space(str[i]) && is_space(str[i - 1]))
			count++;
		if (i == 0 && !is_space(str[i]))
			count++;
		i++;
	}
	return (count);
}

char	*cut_and_paste(char *str, int start, int end)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = end - start + 1;
	word = malloc(sizeof(char) * len);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**matrix;
	int		i;
	int		num_words;
	int		start;

	i = 0;
	num_words = 0;
	matrix = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!matrix)
		return (NULL);
	while (str[i])
	{
		if (i > 0 && !is_space(str[i]) && is_space(str[i - 1]))
			start = i;
		if (i == 0 && !is_space(str[i]))
			start = i;
		if (!is_space(str[i]) && (is_space(str[i + 1]) || str[i + 1] == '\0'))
		{
			matrix[num_words] = cut_and_paste(str, start, i);
			num_words++;
		}
		i++;
	}
	matrix[num_words] = NULL;
	return (matrix);
}
/*
int	main()
{
	char	*str = "Hola que tal";
	char	**res;
	int		i;

	res = ft_split(str);
	i = 0;
	while (i < 3)
	{
		printf("%s\n", res[i]);
		i++;
	}
	return (0);
}*/
