/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:40:19 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/12 16:48:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*res;
	
	i = 0;
	len = end - start + 1;
	if (start > end)
		len = start - end + 1;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (start >= end)
	{
		res[i] = start;
		i++;
		start--;
	}
	while (end >= start)
	{
		res[i] = start;
		i++;
		start++;
	}
	return (res);
}

int	main(void)
{
	int	*tab;
	int	idx;
	int	start;
	int	end;
	int	size;

	idx = 0;
	start = 3;
	end = 5;
	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	tab = ft_range(start, end);
	while (idx < size)
	{
		printf("%i", tab[idx]);
		idx++;
	}
	printf("\n");
}
