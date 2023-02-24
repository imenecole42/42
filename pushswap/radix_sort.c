/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:39:18 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 16:10:31 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	strlen_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
	{
		i++;
	}
	return (i);
}

int	is_empty(int *stack)
{
	if (strlen_stack(stack) == 0)
		return (0);
	return (1);
}

void	radix_sort(int *stack_a, int *stack_b, int size)
{
	int	j;
	int	i;

	i = 0;
	while (!a_is_sorted(stack_a, size))
	{
	j = 0;
		while (j < size)
		{
			if (((stack_a[0] >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		while (is_empty(stack_b))
			push_a(stack_a, stack_b);
		i++;
	}
}

void	sort_stack(int *stack_a, int *stack_b, int argc)
{
	if (argc == 2)
		tri_2(stack_a);
	if (argc == 3)
		tri_3(stack_a);
	if (argc == 4)
		tri_4(stack_a, stack_b);
	if (argc == 5)
		tri_5(stack_a, stack_b);
	if (argc > 5)
		radix_sort(stack_a, stack_b, argc);
}
/*
int main(void)
{
    static int *A;
    static int *B;
A = malloc(sizeof(int) * 16);
B = malloc(sizeof(int) * 16);
    A[0] = 4;
    A[1] = 3;
    A[2] = 11;
    A[3] = 9;
    A[4] = 1;
	A[5] = 6;
    A[6] = 8;
    A[7] = 10;
    A[8] = 5;
    A[9] = 2;
    A[10] = 7;
    A[11] = 13;
    A[12] = 12;
    A[13] = 0;
   // A[11] = 0;
    B[0] = 0;
    //printf("%d",ft_max(T,5));
	//printf("%d",ft_min(T,5));
	radix_sort(A,B);
	printf("%d\n", A[0]);
    printf("%d\n", A[1]);
	printf("%d\n", A[2]);
	printf("%d\n", A[3]);
	printf("%d\n", A[4]);
    printf("%d\n", A[5]);
    printf("%d\n", A[6]);
    printf("%d\n", A[7]);
	printf("%d\n", A[8]);
	printf("%d\n", A[9]);
	printf("%d\n", A[10]);
    printf("%d\n", A[11]);
    printf("%d\n", A[12]);
    printf("%d\n", A[13]);
    //printf("%d\n\n", A[5]);
    printf("tableau stack b\n%d\n", B[0]);
    free(A);
    free(B);
}
*/
