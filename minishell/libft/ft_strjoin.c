/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:55:35 by omechri           #+#    #+#             */
/*   Updated: 2021/12/11 13:20:46 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rslt;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	rslt = malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (!rslt)
		return (NULL);
	while (s1[i] != '\0')
	{
		rslt[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		rslt[i] = s2[j];
		i++;
		j++;
	}
	rslt[i] = '\0';
	return (rslt);
}
/*
int main()
{
	printf("%s\n", ft_strjoin("bon", "soir"));
}
*/
