#include "minishell.h"
int main(int argc,char **argv,char **env)
{
	(void)argc;
	(void)argv;
	t_data mini;
	creat_env(env,&mini);
	ft_env(&mini);
}
