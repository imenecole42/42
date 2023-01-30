
#include "minishell.h"

int creat_env(char **env,t_data *mini)
{
	int i=0;
	int j=0;
	while(env[i])
		i++;
	mini->env=malloc(sizeof(char*)*(i+1));
	if(!mini->env)
		return(0);
	mini->env[i]=0;
	while(env[j])
	{
		mini->env[j]=ft_strdup(env[j]);
		j++;
	}
	return(0);
}

void realloc_env(t_data *mini,char *str)
{
	int i=0;
	int j=0;
	char **temp;
	while(mini->env[i])
		i++;
	temp=malloc(sizeof(char*)*(i+2));
	if(!temp)
		return;
	temp[i+1]=0;
	while(mini->env[j])
	{
		temp[j]=mini->env[j];
		j++;
	}
	//free(mini->env);
	temp[i]=ft_get_add_env(mini,str);
	//temp[i]=ft_strdup(str);
	free(mini->env);
	mini->env=temp;
}

int ft_env(t_data *mini)
{
	int i=0;
	while(mini->env[i])
	{
		printf("%s\n",mini->env[i]);
		i++;

	}
	return(0);
}
