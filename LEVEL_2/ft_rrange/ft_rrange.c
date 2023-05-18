/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:08:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/15 16:18:05 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*tab;
	int	len;

	i = 0;
	len = end - start + 1;
	if (start > end)
		len = start - end + 1;
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	while (start <= end)
	{
		tab[i] = end; 
		i++;
		end--;
	}
	while (end <= start)
	{
		tab[i] = end;
		i++;
		end++;
	}
	return (tab);
}

int	main(void)
{
	int	*tab;
	int	idx;
	int	start;
	int	end;
	int	size;

	idx = 0;
	start = 0;
	end = -3;
	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	tab = ft_rrange(start, end);
	while (idx < size)
	{
		printf("%i", tab[idx]);
		idx++;
	}
	printf("\n");
}
