/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:03:37 by omechri           #+#    #+#             */
/*   Updated: 2021/12/10 16:51:26 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft( unsigned int i, char *c)
{
	printf("\n %c\n",*c);
	i = i;
}*/

void	ft_striteri(char *s, void (*ft)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{	
			(*ft)(i, s + i);
			i++;
		}
	}
}

/*int main(int argc, char **argv)
{
	(void) argc ;
	void (*ptr)( unsigned int, char*);
	ptr = &ft;

	 ft_striteri(argv[1], ptr);

}*/
