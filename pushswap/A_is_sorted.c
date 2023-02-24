/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_is_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 11:14:15 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_double(int *A, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (A[i] == A[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	a_is_sorted(int *T, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (T[i] > T[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sort_tab(int *a, int *copy, int n)
{
	int	x;
	int	y;
	int	index;

	x = 0;
	if (check_double(a, n))
		return (0);
	while (x < n)
	{
		index = 1;
		y = 0;
		while (y < n)
		{
			if (a[x] > a[y])
				index = index + 1;
		y++;
		}
	copy[x] = index;
	x++;
	}
	return (1);
}

int	ft_index_tab(int *stack, int n)
{
	int	*copy;
	int	i;

	copy = NULL;
	copy = malloc(n * sizeof(*copy));
	if (!copy)
		return (0);
	if (!ft_sort_tab(stack, copy, n))
	{
		free(copy);
		ft_erreur(stack);
	}
	ft_sort_tab(stack, copy, n);
	i = 0;
	while (i < n)
	{
		ft_swap(&copy[i], &stack[i]);
	i++;
	}
	free(copy);
	return (1);
}
/*
int main(void)
{
    int *T;
    //int *copy;

    T = malloc(sizeof(int) * 7);
    T[0] = 1;
    T[1] = -20;
    T[2] = 3;
    T[3] = -4;
    T[4] = 55;
	T[5] = 60;
    printf("%d\n", T[0]);
    printf("%d\n", T[1]);
    printf("%d\n", T[2]);
    printf("%d\n", T[3]);
    printf("%d\n", T[4]);
	printf("%d\n", T[5]);
    //copy = malloc(sizeof(int) * 5);
//    copy = ft_index_tab(T, copy);
    //printf("%d\n\n",check_double(T, 5));
    ft_index_tab(T,6);
    //printf("%d\n", copy[1]);
    //printf("%d\n", copy[2]);
    //printf("%d\n", copy[3]);
    //printf("%d\n", copy[4]);
    printf("tableau index\n\n\n");
    printf("%d\n", T[0]);
    printf("%d\n", T[1]);
    printf("%d\n", T[2]);
    printf("%d\n", T[3]);
    printf("%d\n", T[4]);
    printf("%d\n", T[5]);
   free(T);
   //free(copy);
}
*/