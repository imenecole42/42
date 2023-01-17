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