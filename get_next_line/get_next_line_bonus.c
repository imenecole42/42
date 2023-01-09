/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:06 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/16 10:22:18 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_select(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		dest = (char *) malloc(sizeof(char) * (i + 2));
	else if (str[i] == '\0')
		dest = (char *) malloc(sizeof(char) *(i + 1));
	if (!dest)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		dest[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		dest[j++] = '\n';
	dest[j] = '\0';
	return (dest);
}

char	*ft_select2(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (NULL);
	if (str[i] == '\n')
		dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	while (str && str[i])
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*get_read_line(int fd, char *str)
{
	char	*buff;
	char	*temp;
	int		res;

	res = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (res > 0 && (!str || !ft_strchr(str, '\n')))
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[res] = '\0';
		temp = str;
		str = ft_strjoin(temp, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*temp;
	char		*ligne;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = get_read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	if (!str[fd][0])
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	ligne = ft_select(str[fd]);
	temp = ft_select2(str[fd]);
	if (str[fd] != NULL)
		free(str[fd]);
	str[fd] = temp;
	return (ligne);
}
/*
int main()
{
	int fd[3]; 
	int i;

	fd[0] = open("coucou",O_RDONLY);
	fd[1] = open("bonjour",O_RDONLY);
	fd[2] = open("ecole42",O_RDONLY);
	char *ligne;
	ligne == NULL;
	char *res ;
	i = 0;
	while(1)
	{
		ligne = get_next_line(fd[i]);
		i ++;
		if (i>2)
			i = 0;
		if (!ligne)
			break ;
		if (ligne != NULL)
			printf("[%s]",ligne);
		free(ligne);
	}
	return (0);
}
*/
/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
    }
}
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(av[ac-1], O_RDONLY);
	while (get_next_line(fd))
	{
		ft_putendl_fd(line,fd);
	}
	close(fd);
}
*/
