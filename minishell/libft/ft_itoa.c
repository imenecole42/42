/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:37:15 by omechri           #+#    #+#             */
/*   Updated: 2021/12/17 17:09:37 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	longueur(int n)
{
	int			count;
	long int	longnumber;

	count = 0;
	longnumber = n;
	if (longnumber < 0)
	{
		count ++;
		longnumber = -longnumber;
	}
	if (longnumber == 0)
		return (1);
	while (longnumber > 0)
	{
		longnumber = longnumber / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*str;
	long int	nbr;

	count = longueur(n);
	str = malloc ((count + 1) * sizeof (char));
	if (!str)
		return (NULL);
	nbr = n;
	if (n == 0)
		str[0] = 48;
	str[count] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[count - 1] = nbr % 10 + '0';
		count--;
		nbr = nbr / 10;
	}
	return (str);
}
/*
int main ()
{
	printf( "%s \n", ft_itoa(0));
	printf( "%s \n", ft_itoa(9));
	printf( "%s \n", ft_itoa(-9));
	printf( "%s \n", ft_itoa(10));
	printf( "%s \n", ft_itoa(-10));
	printf( "%s \n", ft_itoa(8124));
	printf( "%s \n", ft_itoa(-9874));
	printf( "%s \n", ft_itoa(543000));
	printf( "%s \n", ft_itoa(-2147483648LL));
	printf( "%s \n", ft_itoa(2147483647));
}*/
