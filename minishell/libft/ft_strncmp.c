/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:54:27 by omechri           #+#    #+#             */
/*   Updated: 2021/12/09 12:11:01 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *first, const char *second, size_t length)
{
	if (length > ft_strlen(first))
		length = ft_strlen(first) + 1;
	if (length > ft_strlen(second))
		length = ft_strlen(second) + 1;
	return (ft_memcmp(first, second, length));
}
