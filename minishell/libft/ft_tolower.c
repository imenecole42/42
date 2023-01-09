/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:51:55 by omechri           #+#    #+#             */
/*   Updated: 2021/12/06 16:37:32 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character )
{
	if (character >= 65 && character <= 90)
		character = character + 32;
	return (character);
}
/*
printf( "coucou");
printf(" \n %c", ft_tolower(100));
printf( " %c" , ft_tolower( 70));
printf( " %d", ft_tolower(-1));

printf("\n %c", tolower(100));
printf( " %c" , tolower( 70));
printf( " %d", tolower(-1));
*/
