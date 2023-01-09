/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:45:51 by omechri           #+#    #+#             */
/*   Updated: 2021/12/13 13:06:45 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrmots(char const *string, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (string[0] != c && string[0] != '\0')
		count ++;
	while (string[i] != '\0')
	{
		if (string[i] == c && string[i + 1] != c && string[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static void	writeword(char *dest, const char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != c && string[i] != '\0')
	{
		dest[i] = string[i];
		i++;
	}
	dest[i] = '\0';
}

static int	freetab(char **tab, int index)
{
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	return (2);
}

static int	writewords(char **tab, const char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			tab[k] = malloc(sizeof(char) * (j + 1));
			if (!tab[k])
				return (freetab(tab, k - 1));
			writeword(tab[k], str + i, c);
			i = i + j;
			k++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**rslt;
	int		valretour;

	if (s == NULL)
		return (NULL);
	count = nbrmots(s, c);
	rslt = (char **) malloc ((count + 1) * sizeof (char *));
	if (!rslt)
		return (NULL);
	rslt[count] = NULL;
	valretour = writewords(rslt, s, c);
	if (valretour == 2)
		return (NULL);
	return (rslt);
}
/*
int main ()//reste a verifier le cas ou chaine vide et le delimiteur vide
{
	char ** rslt;
	int i = 0;
//	if (!(rslt = ft_split("", 'z')))
//			printf("NULL");
//	else
//		if (!rslt[0])
//			printf("ok\n");


	rslt = ft_split("ztripouillez",'z');
	while(rslt[i] != NULL)
	{
		printf("kkkk%skk\n",rslt[i]);
		i++;
	}
	free (rslt);
	rslt[count] = malloc (sizeof (char));
}*/
