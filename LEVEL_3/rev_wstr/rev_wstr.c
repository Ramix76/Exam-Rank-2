/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:26:04 by framos-p          #+#    #+#             */
/*   Updated: 2023/04/26 14:59:14 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

	count = 0;
	i = 0;
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
	char	*words;
	int		i;
	int		len;

	i = 0;
	len = end - start + 1;
	words = malloc(sizeof(char) * len);
	if (!words)
		return (NULL);
	while (i < len)
	{
		words[i] = str[start + i];
		i++;
	}
	words[i] = '\0';
	return (words);
}

char	**ft_split(char *str)
{
	char	**matrix;
	int		start;
	int		i;
	int		num_words;

	i = 0;
	start = 0;
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

void	print_str(char *str)
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
	if (argc == 2)
	{
		int		num_words;
		char	*str;
		char	**matrix;

		str = argv[1];
		matrix = ft_split(str);
		num_words = count_words(str);
		while (--num_words > 0)
		{
			print_str(matrix[num_words]);
			write(1, " ", 1);
		}
		if (num_words == 0)
		{
			print_str(matrix[num_words]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
