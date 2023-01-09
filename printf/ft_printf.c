/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:51 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/09 12:00:21 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_type_parametre(va_list arg, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_print_s(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_di(va_arg(arg, int)));
	else if (format == 'p')
		return (ft_print_p(va_arg(arg, unsigned long long int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_x(va_arg(arg, unsigned int), format));
	else if (format == 'u')
		return (ft_print_u(va_arg(arg, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type_parametre(arg, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
/*
#include <stdio.h>

int main( void )
{
	 int x = 50;
   int *ptr = &x;
   printf("The address is: %p \n", ptr);
   ft_printf("The address is: %p \n",ptr);

   ft_printf ("Characters: %c %c \n", 65,'a');
   printf ("Characters: %c %c \n", 65,'a');
    ft_printf ("Decimals: %d \n", 197555557);
    printf ("Decimals: %d \n", 197555557);
ft_printf ("Some different radices: %d %x  \n", 100, 100);
printf ("Some different radices: %d %x  \n", 100, 100);
ft_printf ("Characters: %c\n", 65);
printf ("Characters: %c\n", 65);
}
*/
