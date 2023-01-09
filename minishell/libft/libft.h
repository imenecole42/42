/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:04:08 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 15:19:26 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<string.h>
# include<stdlib.h>
# include<unistd.h>

void	*ft_memset(void *s, int c, size_t n);
int		ft_isalpha(int str);
int		ft_isdigit(int nb);
int		ft_isalnum(int nb);
int		ft_isascii( int c);
int		ft_isprint( int c);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int character );
int		ft_tolower(int character );
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strrchr( const char *string, int searchedChar );
int		ft_strncmp( const char *first, const char *second, size_t length);
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size);
void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_atoi(const char *str);
char	*ft_strdup( const char *source );
void	*ft_calloc(size_t elementCount, size_t elementSize );
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*ft)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
