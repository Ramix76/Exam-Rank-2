/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:27:53 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/16 14:51:15 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		if (begin_list->data)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

void	print(void *str)
{
	printf("%s\n", str);
}

int	main()
{
	t_list	*a = malloc(sizeof(t_list));
	t_list	*b = malloc(sizeof(t_list));
	t_list	*c = malloc(sizeof(t_list));

	a->data = "Hola";
	b->data = "que";
	c->data = "tal";

	a->next = b;
	b->next = c;

	ft_list_foreach(a, print);
}
