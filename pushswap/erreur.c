/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:12:39 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 19:03:24 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_erreur(int *Stack)
{
	ft_putstr("Error\n");
	free(Stack);
	exit(EXIT_FAILURE);
}

void	erreur(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_free(int *A)
{
	free(A);
	exit(EXIT_FAILURE);
}

void	ft_check(int *stack, int argc)
{
	if (check_double(stack, argc))
	{
		ft_putstr("Error\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
}

void	ft_sort(int *stack, int argc)
{
	if (a_is_sorted(stack, argc))
		ft_free(stack);
}
