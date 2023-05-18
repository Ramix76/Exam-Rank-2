/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:15:38 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/09 12:30:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
		if (i == 0 && !is_space(str[i]))
			count++;
		if (i > 0 && !is_space(str[i]) && is_space(str[i - 1]))
			count++;
		i++;
	}
	return (count);
}

char	*cut_and_paste(char *str, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = end - start + 1;
	word = malloc(sizeof(char) * len);
	if (!word)
		return (NULL);
	while ( i < len)
	{
		word[i] = str[i + start];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**matrix;
	int		start;
	int		i;
	int		num_words;

	i = 0;
	num_words = 0;
	start = 0;
	matrix = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!matrix)
		return (NULL);
	while (str[i])
	{
		if (i == 0 && !is_space(str[i]))
			start = i;
		if (i > 0 && !is_space(str[i]) && is_space(str[i - 1]))
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

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		char	**matrix;
		char	*str;
		int		i;
		int		num_words;

		str = argv[1];
		matrix = ft_split(str);
		num_words = count_words(str);
		if (num_words > 1)
		{
			i = 1;
			while (i < num_words)
			{
				putstr(matrix[i]);
				write(1, " ", 1);
				i++;
			}
		}
		putstr(matrix[0]);
	}
	printf("\n");
	return (0);
}
