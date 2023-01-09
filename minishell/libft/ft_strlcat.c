/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:50:19 by omechri           #+#    #+#             */
/*   Updated: 2021/12/10 10:40:02 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	j;
	size_t			len_tot;
	unsigned int	i;

	j = 0;
	i = 0;
	while ((i < size) && dst[i] != '\0')
		i++;
	len_tot = ft_strlen(src) + ft_strlen(dst);
	if (i == size)
		return (ft_strlen(src) + i);
	while (src[j] != '\0' && ((j + i) < (size - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len_tot);
}
//tester ft-strlcat
/*int main ()
{
	char s1a[10] = "Test1";
	char s2a[] = "OK";
	char s3a[10] = "Same";
	char s4a[] = "Size";
	char s5a[20] = "Shorter";
	char s6a[] = "ThanMyself";
	char s7a[20] = "Shorter";
	char s8a[] = "ThanMyself";
	printf("%s  %zu  \n",s1a, ft_strlcat(s1a, s2a, 6) );
	printf("%s  %zu \n", s3a, ft_strlcat(s3a, s4a, 10) );
	printf("%s  %zu \n",s5a,  ft_strlcat(s5a, s6a, 4) );
	printf("%s  %zu \n", s7a, ft_strlcat(s7a, s8a, 0) );
}*/
