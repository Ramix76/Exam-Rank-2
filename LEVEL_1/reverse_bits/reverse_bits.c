/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:14:31 by framos-p          #+#    #+#             */
/*   Updated: 2023/05/11 16:28:52 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	bit;
	
	bit = 0;
	bit += ((octet & 128) >> 7);
	bit += ((octet & 64) >> 5);
	bit += ((octet & 32) >> 3);
	bit += ((octet & 16) >> 1);
	bit += ((octet & 8) << 1);
	bit += ((octet & 4) << 3);
	bit += ((octet & 2) << 5);
	bit += ((octet & 1) << 7);
	return (bit);
}
/*
int	main()
{
	unsigned char c = 'A';
	printf("%u\n", c);
	printf("%u\n", reverse_bits(c));
	return (0);
}
*/
