/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:11:42 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/17 15:34:31 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check(const char *str, const char *find, size_t t)
{
	size_t	a;

	a = 0;
	while (find[a] != '\0')
	{
		if (str[t + a] != find[a])
			return (0);
		a++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	t;
	size_t	findsize;
	int		ret;
	char	*test;

	t = 0;
	findsize = 0;
	ret = 0;
	test = (char *)str;
	if (find[0] == '\0')
		return (test);
	if (str[0] == '\0')
		return (NULL);
	findsize = ft_strlen(find);
	while (t + findsize <= len)
	{
		if (test[t] == find[0])
		{
			ret = ft_check(test, find, t);
			if (ret == 1)
				return (&test[t]);
		}
		t++;
	}
	return (NULL);
}
