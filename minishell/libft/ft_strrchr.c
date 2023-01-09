/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:53:43 by omechri           #+#    #+#             */
/*   Updated: 2021/12/11 10:39:53 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *string, int searchedChar )
{
	int	len;

	len = ft_strlen(string);
	while (len >= 0)
	{
		if (string[len] == (char) searchedChar)
			return ((char *) &string[len]);
		len --;
	}
	return (NULL);
}
//tester strrchr
/*
int main(){
const char * source = "the C Language";
    char * destination;
   char * pointer;
    int length = strlen( source );

      destination = (char *) malloc( sizeof( char) * (length+1) );
    strcpy( destination, source );

    pointer = ft_strrchr( destination, 't') ;
    *pointer = 'T';


    printf( "Result : %s\n", destination );
    free( destination );
    return 0;
    }
*/
