/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:39:29 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 16:35:55 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_min(int *T)
{
	int	i;
	int	min;

	min = T[0];
	i = 1;
	while (T[i] != 0)
	{
		if (T[i] < min)
			min = T[i];
		i++;
	}
	return (min);
}

void	tri_2(int *A)
{
	int	i;

	i = 0;
	if (A[i] > A[i + 1])
	{
		swap_ab(A);
		ft_putstr("sa\n");
	}
}

void	tri_3(int *T)
{
	if ((T[0] > T[1]) && (T[0] > T[2]))
	{
		r_ab(T);
		ft_putstr("ra\n");
	}
	if ((T[1] > T[2]) && (T[1] > T[2]))
	{
		rr_ab(T);
		ft_putstr("rra\n");
	}
	if (T[0] > T[1])
	{
		swap_ab(T);
		ft_putstr("sa\n");
	}
}

void	tri_4(int *A, int *B)
{
	int	i;
	int	min;

	i = 0;
	min = ft_min(A);
	while (A[0] != min)
	{
		if (A[i] != min)
		{
			if (A[3] == min || A[2] == min)
			{
				rr_ab(A);
				ft_putstr("rra\n");
			}
			else
				rotate_a(A);
		}
		i++;
	}
	push_b(A, B);
	tri_3(A);
	push_a(A, B);
}

void	tri_5(int *A, int *B)
{
	int	i;
	int	min;

	i = 0;
	min = ft_min(A);
	while (A[0] != min)
	{
		if (A[i] != min)
		{
			if (A[4] == min || A[3] == min)
			{
				rr_ab(A);
				ft_putstr("rra\n");
			}
			else
				rotate_a(A);
		}
	i++;
	}
	push_b(A, B);
	tri_4(A, B);
	push_a(A, B);
}
/*
int main(void)
{
    static int *A;
    static int *B;
    A = malloc(sizeof(int) * 6);
   B = malloc(sizeof(int) * 6);
    A[0] = 990;
    A[1] = 116;
    A[2] = 110;
    A[3] = -414;
    A[4] = -366;
	A[5] = 0;
    B[0] = 0;
    	//printf("%d",ft_max(T,5));
	//printf("%d",ft_min(T,5));
	tri_5(A,B);
	printf("%d\n", A[0]);
    printf("%d\n", A[1]);
	printf("%d\n", A[2]);
	printf("%d\n", A[3]);
	printf("%d\n\n", A[4]);
    free(A);
	free(B);
}
*/
