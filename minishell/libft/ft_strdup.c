/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:33:45 by omechri           #+#    #+#             */
/*   Updated: 2021/12/08 16:41:42 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup( const char *source)
{
	char	*destination;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(source);
	destination = malloc((len + 1) * sizeof(char));
	if (destination == NULL)
		return (NULL);
	while (i <= len)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
