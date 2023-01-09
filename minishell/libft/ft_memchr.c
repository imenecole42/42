/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:47:33 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 12:04:00 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size)
{
	const char	*memblock;
	size_t		i;

	memblock = memoryBlock;
	i = 0;
	while (i < size)
	{
		if (memblock[i] == (char) searchedChar)
			return ((char *) &memblock[i]);
		i++;
	}
	return (NULL);
}
/*
int main() {
    char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    const unsigned int size = 10;
    // On recherche une valeur inhéxistante :
    void * found = ft_memchr( data, 57, size );
    printf( "57 is %p\n",  found );
    // On recherche une valeur existante :
    found = ft_memchr( data, 50, size );
    printf( "50 is %p\n",  found  );
    if ( found != NULL ) {
        printf( "La valeur à la position calculée est %d\n", *((char *) found) );
    }
    return EXIT_SUCCESS;
}*/
