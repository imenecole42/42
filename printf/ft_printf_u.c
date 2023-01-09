/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:30:28 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/09 12:31:24 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//format u 
size_t	ft_nbr(long nbr)
{
	long	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_u(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10);
		nbr %= 10;
	}
	ft_putchar(nbr + 48);
}

size_t	ft_print_u(unsigned int nbr)
{
	ft_putnbr_u(nbr);
	return (ft_nbr(nbr));
}
