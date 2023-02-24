/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:38:14 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 16:15:40 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ss_ab(int *A, int *B)
{
	swap_ab(A);
	swap_ab(B);
}

void	ft_rotate_rr(int *A, int *B)
{
	r_ab(A);
	r_ab(B);
}

void	ft_rrotate_rr(int *A, int *B)
{
	rr_ab(A);
	rr_ab(B);
}

void	rotate_a(int *A)
{
	r_ab(A);
	ft_putstr("ra\n");
}

void	push_a(int *A, int *B)
{
	pab(B, A);
	ft_putstr("pa\n");
}
