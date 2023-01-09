/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:03:31 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 12:12:10 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	if (pointer1 == NULL && pointer2 == NULL)
		return (0);
	ptr1 = (unsigned char *) pointer1;
	ptr2 = (unsigned char *) pointer2;
	while (i < size)
	{
		if (ptr1[i] == ptr2[i])
			i++;
		else
			return (ptr1[i] - ptr2[i]);
	}
	return (0);
}
/*
int main() {

//    int array1 [] = { 54, 85, 20, 63, 21 };
//    int array2 [] = { 54, 85, 19, 63, 21 };
  //  size_t size = sizeof( int ) * 5;



    printf("\200    \n %d   %d  \n ",  memcmp("t\200", "t\0", 2) , 
    ft_memcmp("t\200", "t\0", 2));
  //  printf(" %d   %d  \n ",  memcmp( array1, array1, size) , 
  //  ft_memcmp( array1, array1, size) );
  //  printf( " %d  %d   \n",  memcmp( array2, array1, size) , 
  //  ft_memcmp( array2, array1, size) );

    return 0;
}*/
