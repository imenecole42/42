/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:22:25 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/09 12:06:36 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdbool.h>

size_t	ft_putchar(char c);
int		ft_print_s(char *s);
size_t	ft_hexa_len(unsigned long long int n);
void	ft_print_lower_x(unsigned long long int n);
void	ft_print_upper_x(unsigned long long int n);
size_t	ft_print_x(unsigned int n, char c);
size_t	ft_print_p(unsigned long long int n);
size_t	ft_put(long nbr);
void	ft_putnbr(int nb);
int		ft_print_di(unsigned long long nbr);
size_t	ft_nbr(long nbr);
void	ft_putnbr_u(unsigned int nbr);
size_t	ft_print_u(unsigned int nbr);
size_t	ft_type_parametre(va_list arg, const char format);
int		ft_printf(const char *str, ...);
#endif
