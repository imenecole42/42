/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:21:58 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/09 12:34:37 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//format x et X
size_t	ft_hexa_len(unsigned long long int n)
{
	size_t	len;

	len = (n == 0);
	while (n)
	{
		n /= 16;
		len ++;
	}
	return (len);
}

void	ft_print_lower_x(unsigned long long int n)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
		ft_print_lower_x(n / 16);
	ft_putchar(hexa[n % 16]);
}

void	ft_print_upper_x(unsigned long long int n)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
		ft_print_upper_x(n / 16);
	ft_putchar(hexa[n % 16]);
}

size_t	ft_print_x(unsigned int n, char c)
{
	if (c == 'x')
		ft_print_lower_x(n);
	else if (c == 'X')
		ft_print_upper_x(n);
	return (ft_hexa_len(n));
}
//format ptr p

size_t	ft_print_p(unsigned long long int n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_print_lower_x(n);
	return (ft_hexa_len(n) + 2);
}
