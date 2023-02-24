/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:39:07 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/06 19:04:00 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

int		check_double(int *A, int n);
int		a_is_sorted(int *T, int n);
int		ft_sort_tab(int *a, int *copy, int n);
int		ft_index_tab(int *stack, int n);
int		ft_min(int *T);
int		ft_index_tab(int *stack, int n);
int		strlen_stack(int *stack);
int		is_empty(int *stack);
int		is_digit(int c);
int		is_empty(int *stack);
void	ss_ab(int *A, int *B);
void	ft_rotate_rr(int *A, int *B);
void	ft_rrotate_rr(int *A, int *b);
void	swap_ab(int *T);
void	r_ab(int *T);
void	rr_ab(int *T);
void	pab(int *A, int *B);
void	ft_putchar(char c );
void	ft_putstr(char *str);
void	tri_2(int *A);
void	tri_3(int *T);
void	tri_4(int *A, int *B);
void	tri_5(int *A, int *B);
void	ft_erreur(int *Stack);
void	radix_sort(int *stack_a, int *stack_b, int size);
void	erreur(void);
void	sort_stack(int *stack_a, int *stack_b, int argc);
long	ft_atoi(const char *str, int *stack_a);
void	ft_free(int *A);
void	rotate_a(int *A);
void	push_a(int *A, int *B);
void	push_b(int *A, int *B);
void	ft_swap(int *a, int *b);
void	ft_check(int *stack, int argc);
void	ft_sort(int *stack, int argc);
void	ft_sort(int *stack, int argc);
void	ft_check_sort(int *stack, int argc);
#endif
