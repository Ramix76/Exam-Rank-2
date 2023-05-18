/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:15:00 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/13 15:14:14 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	swap;
	unsigned int	i;

	i = 0;
	if (size <= 1)
		return ;
	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = -1;
		}
		i++;
	}
}

int main()
{
	unsigned int	i;
	int array[] = {3, 4, 1, 7, 6, 2, 8, 5, 9};
	unsigned int size = sizeof(array) / sizeof(int);

	printf("Arreglo original:\n");
	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	sort_int_tab(array, size);
	printf("Arreglo ordenado:\n");
	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	return 0;
}
