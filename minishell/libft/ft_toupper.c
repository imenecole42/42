/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:51:21 by omechri           #+#    #+#             */
/*   Updated: 2021/12/06 16:34:02 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character )
{	
	if (character >= 97 && character <= 122)
		character = character - 32;
	return (character);
}

// tester toupper
/*printf( "coucou");
printf(" \n %c", ft_toupper(100));
printf( " %c" , ft_toupper( 50));
printf( " %d", ft_toupper(-1));

printf("\n %c", toupper(100));
printf( " %c" , toupper( 50));
printf( " %d", toupper(-1));
*/
