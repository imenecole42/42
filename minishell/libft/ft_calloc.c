/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:01:21 by omechri           #+#    #+#             */
/*   Updated: 2021/12/08 16:49:00 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize )
{
	void	*rslt;

	rslt = malloc(elementCount * elementSize);
	if (!rslt)
		return (NULL);
	ft_bzero(rslt, elementCount * elementSize);
	return (rslt);
}
/*
int main() {

    int i;
    int * pointer = (int *) malloc( 10 * sizeof(int) );


 
    for ( i=0; i<10-1; i++ ) {
    pointer[i] = i;
    }
	for (i=0; i<10; i++ ) {
    printf( "%d ", pointer[i] );
    }


 pointer = (int *) ft_calloc( 10, sizeof(int) );

    for (i=0; i<10; i++ ) {
     printf( "%d ", pointer[i] );
    }
    printf( "\n" );

    free( pointer );

    return 0;
}*/
