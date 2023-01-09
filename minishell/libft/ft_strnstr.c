/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:24:20 by omechri           #+#    #+#             */
/*   Updated: 2021/12/08 16:26:22 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (s2 [0] == '\0')
		return ((char *)(s1));
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s2[j] == s1[i + j] && ((i + j) < len))
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char *grande = "bonjour";
	char * petite= "jour";
	//printf ( " %s \n" , strnstr(grande, petite, 4));
	printf ( " %s \n" , ft_strnstr(grande, petite, 4));
}
*/
