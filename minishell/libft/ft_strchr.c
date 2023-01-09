/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:53:11 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 12:20:48 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char) searchedChar)
		{
			return ((char *) &string[i]);
		}
		i++;
	}
	if (searchedChar == 0)
		return ((char *) &string[i]);
	return (NULL);
}
/*
//tester strchr
int main ()
{// const char * source = "the c language";
	const char *src1 = "bonjour";
   // char * destination;
 //char * pointer;
 //  char * toto;
  //  int length = strlen( source );
    
    //  destination = (char *) malloc( sizeof( char) * (length+1) );
   // strcpy( destination, source );
	if (strcmp( ft_strchr( src1, '\0') ,strchr(src1, '\0'))== 0)
		printf( " \n la fonction du c donne toto :\n");
    printf( " \nft  pointer : \n" );

 //   free( destination );
    return 0;
}*/
