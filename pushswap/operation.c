/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:38:40 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 16:18:32 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_ab(int *T)
{
	int	temp;

	temp = T[0];
	T[0] = T[1];
	T[1] = temp;
}

void	r_ab(int *T)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = T[0];
	while (T[i] != 0)
	{
		T[i] = T[i + 1];
		i++;
	}
	T[i - 1] = tmp;
}

void	rr_ab(int *T)
{
	int	tmp;
	int	i;

	i = 0;
	while (T[i] != 0)
		i++;
	tmp = T[--i];
	while (T[i])
	{
		T[i] = T[i - 1];
		i--;
	}
	T[0] = tmp;
}

void	pab(int *A, int *B)
{
	int	i;

	i = 0;
	while (B && B[i] != 0)
		i++;
	B[i + 1] = 0;
	i--;
	while (B && i >= 0)
	{
		B[i + 1] = B[i];
		i--;
	}
	B[0] = A[0];
	i = 1;
	while (A && A[i])
	{
		A[i - 1] = A[i];
		i++;
	}
	A[i - 1] = 0;
}

void	push_b(int *A, int *B)
{
	pab(A, B);
	ft_putstr("pb\n");
}
/*
int main(void)
{
    static int *T;

    T = malloc(sizeof(int) * 100000);
    T[0] = 5;
    T[1] = 8;
    T[2] = 9;
    T[3] = 4;
    T[4] = 1;
    r_ab(T);
    printf("%d\n", T[0]);
    printf("%d\n", T[1]);
    printf("%d\n", T[2]);
    printf("%d\n", T[3]);
    printf("%d\n", T[4]);
    free(T);
}
*/
