#include "minishell.h"

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
void realloc_export(t_data *mini,char *str)
{
	int i=0;
	int j=0;
	char **temp;
	while(mini->export[i])
		i++;
	temp=malloc(sizeof(char*)*(i+2));
	if(!temp)
		return;
	temp[i+1]=0;
	while(mini->export[j])
	{
		temp[j]=ft_strdup(mini->env[j]);
		j++;
	}
	temp[i]=ft_get_add_export(mini,str);
	free(mini->export);
	mini->export=temp;
}
int print_export(t_data *mini)
{
	int i=0;
	while(mini->export[i])
	{
		printf("export -x ");
		printf("%s",ft_select(mini->export[i]));
		printf("\"%s\"\n",ft_select1(mini->export[i]));
		i++;
	}
	return(0);
}
