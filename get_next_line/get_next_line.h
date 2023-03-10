/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:43:11 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/16 15:30:13 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h> 

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr( char *s, int c);
char	*ft_select(char *str);
char	*ft_select2(char *str);
char	*get_read_line(int fd, char *str);
char	*get_next_line(int fd);
#endif
