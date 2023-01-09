/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:48:36 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 11:28:04 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char		*dest;
	const char	*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	dest = destination;
	src = source;
	while (size)
	{
		*dest = *src;
		dest++;
		src++;
		size --;
	}
	return (destination);
}
//tester memcpy
/*int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );
    for( length=0; length<5; length++ ) {
        printf( "  x =  %d ", copy[ length ] );
    }
    printf( "\n" );
    free( copy );
*/
