/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:46:40 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 12:39:16 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rslt;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		start = ft_strlen(s);
		len = 0;
	}
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	rslt = malloc((len +1) * sizeof(char));
	if (!rslt)
		return (NULL);
	while (i < len && start < ft_strlen(s) && s[start] != '\0')
	{
		rslt[i] = s[start];
		i++;
		start++;
	}
	rslt[i] = '\0';
	return (rslt);
}
/*
int main()
{
//if (start >= slen)
  //              return (NULL);
char	str[] = "lorem ipsum dolor sit amet";
	printf("%s \n " ,ft_substr(str, 400, 20));
}*/