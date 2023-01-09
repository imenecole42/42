/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:21:19 by omechri           #+#    #+#             */
/*   Updated: 2021/12/03 17:37:35 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sig;
	int	nb;

	sig = 1;
	i = 0;
	nb = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -sig;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - '0' ) + nb * 10;
		i++;
	}
	return (nb * sig);
}
/*
int main()
{

	printf( " %d    %d \n", ft_atoi(" \t \n2563"), atoi(" \t \n2563"));
	printf( " %d    %d \n", ft_atoi("-2563"), atoi("-2563"));
	printf( " %d    %d \n", ft_atoi("+2563"), atoi("+2563"));
	printf( " %d    %d \n", ft_atoi("-+-151515"), atoi("-+-151515"));
	printf( " %d    %d \n", ft_atoi("2563"), atoi("2563"));
	printf( " %d    %d \n", ft_atoi("\t-2563"), atoi("\t-2563"));
	printf( " %d    %d \n", ft_atoi("-\t2563"), atoi("-\t2563"));
	printf( " %d    %d \n", ft_atoi("a2563"), atoi("a2563"));
	printf( " %d    %d \n", ft_atoi("-25s63"), atoi("-25s63"));
	printf( " %d    %d \n", ft_atoi("-s2563"), atoi("-s2563"));
}*/
