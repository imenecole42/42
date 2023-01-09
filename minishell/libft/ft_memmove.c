/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:44:28 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 11:52:20 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*move(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n)
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*(d + n -1) = *(s + n - 1);
			n--;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	return (move(dest, src, n));
}
//tester memcpy
/*int main()
{
int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
    copy = (int *) malloc( length );
    ft_memmove( copy, array, length );
    for( length=0; length<5; length++ ) {
        printf( "  x =  %d ", copy[ length ] );
    }
    printf( "\n" );
    free( copy );
    if (dest == NULL || src == NULL)
                return (NULL);
}*/
