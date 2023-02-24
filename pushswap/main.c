/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:38:29 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 19:01:18 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_check_sort(int *stack, int argc)
{
	ft_check(stack, argc);
	ft_sort(stack, argc);
	ft_index_tab(stack, argc);
}

int	is_digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (0);
	return (1);
}

long	ft_atoi(const char *str, int *stack_a)
{
	int		i;
	int		sign;
	long	val;

	i = 0;
	sign = 1;
	val = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		ft_erreur(stack_a);
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i] - 48);
		if ((val * sign) < -2147483648 || (val * sign) > 2147483647)
			ft_erreur(stack_a);
		i++;
	}
	val = val * sign;
	return (val);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*stack_b;

	i = 0;
	stack_a = malloc ((argc + 1) * sizeof (*stack_a));
	if (!stack_a)
		return (0);
	argc = argc - 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i + 1]))
			ft_erreur(stack_a);
		stack_a[i] = ft_atoi(argv[i + 1], stack_a);
	i++;
	}
	ft_check_sort(stack_a, argc);
	stack_b = malloc ((argc) * sizeof (*stack_b));
	if (!stack_b)
		return (0);
	stack_b[0] = 0 ;
	sort_stack(stack_a, stack_b, argc);
	return (free(stack_b), free(stack_a), 0);
}
