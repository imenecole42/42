/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:35:14 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/03 12:50:33 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_join(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen(s1)];
	i++;
	}
	str[i] = '\0';
	free_join(&s1);
	return (str);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen(s1)];
	i++;
	}
	str[i] = '\0';
	return (str);
}
