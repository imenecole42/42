#include "minishell.h"

char *ft_select(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		dest = (char *) malloc(sizeof(char) * (i + 2));
	else if (str[i] == '\0')
		dest = (char *) malloc(sizeof(char) *(i + 1));
	if (!dest)
		return (NULL);
	while (str[j] && str[j] != '=')
	{
		dest[j] = str[j];
		j++;
	}
	if (str[j] == '=')
		dest[j++] = '=';
	dest[j] = '\0';
	return (dest);
}

char	*ft_select1(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (NULL);
	if (str[i] == '=')
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

int creat_export(t_data *mini)
{
	int i=0;
	int j=0;
	while(mini->env[i])
		i++;
	mini->export=malloc(sizeof(char*)*(i+1));
	if(!mini->export)
		return(0);
	mini->export[i]=0;
	while(mini->env[j])
	{
		mini->export[j]=ft_strdup(mini->env[j]);
		j++;
	}
	return(0);
}

int print-export(t_data *mini)
{
	int i=0;
	while(mini->eport[i])
	{
		printf("%s\n",mini->export[i]);
		i++;

	}
	return(0);
}

int	ft_get_plus_export(t_data *mini,char *str)
{
	char	*export;
	int		i;
	i = 0;

	while (!ft_strnstr(mini->env[i],ft_select(str), ft_strlen(ft_select(str))))
		i++;
	if(ft_strnstr(mini->env[i],ft_select(str), ft_strlen(ft_select(str))))
		export = ft_strjoin(mini->envp[i] , ft_select1(str));
	return(0);
}

int is_export(char *str)
{
	int i=0;
	if((str[i]>='a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
		return(1);
	return(0);
}

void ft_var(char *str)
{
	int i;
	i=0;
	char *val;
	char *var
	val=ft_select(str);
	var=ft_select1(str);
	if(val && !var)
	{
		creat_export(mini);
	}

		
	
}
int ft_export(char **argv,int argc ,t_data mini)
{
	char **tmp;
	int i=1;
	int j=0;
	char *var;
	char *val;
	if(i < argc - 1)
		i++;
	if(is_export(argv[i][j]))
	{
		

	}
}
*/
int main()
{
	char *str="lina l= iklkllk";
	printf("%s",ft_print(str));
} 