/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:14:25 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 13:02:03 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exist(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*trim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*rslt;
	int		i;

	i = 0;
	start = 0;
	while (s1[start] && exist(set, s1[start]))
		start++;
	len = ft_strlen(s1);
	while (len > 0 && exist(set, s1[len - 1]))
		len--;
	if (len < start)
		len = start;
	rslt = malloc((len - start + 1) * sizeof(char));
	if (!rslt)
		return (NULL);
	while (start < len)
	{
		rslt[i] = s1[start];
		i++;
		start++;
	}
	rslt[i] = '\0';
	return (rslt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (s1 == NULL)
		return (NULL);
	return (trim(s1, set));
}
/*
int main()
{
	printf("\nss%sss\n",ft_strtrim("   xxx   xxx", " x"));
        //printf("\n%d",check(strcmp(s, ""));

}*/
