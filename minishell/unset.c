#include "minishell.h"

void ft_unset(t_data *mini, char *str)
{
    int i;

	i = 0;
    if(mini->argc > 1)
	{
		while((mini->env[i]) && ft_strcmp(ft_select2(mini->env[i]),str))
			i++;
		printf("%s",mini->env[i]);
		if(mini->env[i] == 0)
			printf("unset jes suis la NON\n\n\n\n\n");
		else 
		{
				printf("unset jes suis la1\n\n\n\n\n");
				realloc_unset(mini, str);
		}

	}
	return;      
}

void realloc_unset(t_data *mini,char *str)
{
	int i;;
	int j;
	int u;

	i = 0;
	j = 0;
	u = 0;
	char **temp;
	while(mini->env[i])
		i++;
	temp=malloc(sizeof(char*)*(i));
	if(!temp)
		return;
	temp[i-1]=0;
	while(!ft_strnstr(mini->env[u],str,ft_strlen(str)))
		u++;
	if(strcmp(ft_select2(mini->env[u]),str)!=0)
	{
		u++;
		while(!ft_strnstr(mini->env[u],str,ft_strlen(str)))
			u++;
	}
    i=0;
	while(i<u)
	{
        temp[j] = mini->env[i];
        j++;
        i++;
	}
	//printf("%s",mini->env[i]);
	if(ft_strnstr(mini->env[i],str,ft_strlen(str)))
	{
        i++;
	}
	printf("%s",mini->env[i]);
    while(mini->env[i])
    {
        temp[j] = mini->env[i];
        j++;
        i++;
    }
	free(mini->env);
	mini->env=temp;
}
