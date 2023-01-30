#include "minishell.h"

void realloc_env_be(t_data *mini, char *str)
{
	char *var;
	char *val;
	char *env;
	char *temp;
	int i=0;
	var = ft_select(str);
	val = ft_select1(str);
	while (!ft_strnstr(mini->env[i], var, ft_strlen(var)))
		i++;
	env=mini->env[i];
	if (is_plus(str))
	{
		temp=ft_strjoin(env,val);
		mini->env[i]=temp;
		printf("\n1111\n");
		printf("%s",mini->env[i]);
	}
	else if (!is_plus(str))
	{
		free(mini->env[i]);
		temp = ft_strdup(str);
		mini->env[i] = temp;
		printf("\n2222\n");
		printf("%s",mini->env[i]);
	}
	return ;
}
char *ft_get_add_env(t_data *mini, char *str)
{
	char *var;
	char *val;
	char *temp;
	var = ft_select(str);
	val = ft_select1(str);
	int i;
	i = 0;
	while ((mini->env[i]) && (!ft_strnstr(mini->env[i], var, ft_strlen(var))))
		i++;
	if (mini->env[i] == 0)
	{
		if (val && !is_plus(str))
		{
			temp = ft_strdup(str);
			mini->env[i] = temp;
			printf("\n333\n");
		}
		else if (val && is_plus(str))
		{
			temp = strdup_plus(str);
			mini->env[i] = temp;
			printf("\n444444\n");
		}
	}
	return(mini->env[i]);
}
void get_env(t_data *mini,char **argv)
{
	int i;
	i = 0;
	while(mini->env[i]&&(!ft_strnstr(mini->env[i], ft_select(argv[2]), ft_strlen(ft_select(argv[2])))))
		i++;
	if(mini->env[i+1] == 0)
		realloc_env(mini,argv[2]);
	else
		realloc_env_be(mini, argv[2]);
			
}
void ft_export(char **argv, int argc, t_data *mini)
{
	if(argc==2)
	{
		print_export(mini);
	}
	if (argc == 3)
	{
		if(is_export(argv[2]) && ft_select1(argv[2]))
		{
			get_env(mini,argv);
			get_export(mini,argv);
		}
		else if(is_export(argv[2]) && !ft_select1(argv[2]))
			get_export(mini,argv);
		else
		{
			write(2, "export: `", 10);
			ft_putstr_fd(argv[2], 2);
			write(2, "': not a valid identifier\n", 27);
		}
	}
	return;
	
}
