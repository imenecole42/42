#include "minishell.h"

int main(int argc,char **argv,char **env)
{
	(void)argc;
	(void)argv;
	t_data mini;
	//printf("%d",is_export(argv[2]));
	creat_env(env,&mini);
	creat_export(&mini);
	ft_export(argv,argc,&mini);
	//ft_env(&mini);
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n");
	print_export(&mini);
	//realloc_env_be(&mini,argv[2]);
	//ft_get_add_env(&mini,argv[2]);
	//realloc_env(&mini,argv[2]);
	//realloc_export(&mini,argv[2]);
	//ft_env(&mini);
	//ft_free(mini.env);
}
