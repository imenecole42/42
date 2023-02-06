#include "minishell.h"

char *get_var_echo(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    int k=0;
    if(str[i]=='$')
      i++;
    while(str[i] && ft_isalnum_mini(str[i]))
        i++;
    dest = (char *) malloc(sizeof(char) * (i+1));
    if (!dest)
        return (NULL);
    if(str[k]=='$')
      k++;
    while (j < i)
    {
        dest[j] = str[k];
        j++;
        k++;
    }
    dest[j]='\0';
    return (dest);
}

char *get_val_echo(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    if(str[i]=='$')
      i++;
    while(str[i] && ft_isalnum_mini(str[i]))
        i++;
    if (!str[i + 1])
        return(0);
    dest = (char *) malloc(sizeof(char) * (ft_strlen(str)- i + 1));
    if (!dest)
        return (NULL);
    while (str[i])
    {
        dest[j] = str[i];
        j++;
        i++;
    }
    dest[j]='\0';
    return (dest);
}

/*int ft_print_var_double(char *str,t_data *mini)
{
	if(check_var(str,mini) != 0)
	{
		printf("%s",check_var(str,mini));
		printf("%s\n",get_val_echo(str));
	}
	else
		printf("%s\n",get_val_echo(str));
    return(0);
}
*/