#include "minishell.h"


int main(int argc,char **argv,char **env)
{
	(void)argc;
	(void)argv;
	int i=0;
	//int j=0;
	t_data mini;
	
	//mini.argc=argc;
	//printf("argc=%d\n",mini.argc);
	//printf("%d",is_export(argv[2]));
	creat_env(env,&mini);
	//ft_pwd(argc);
	//ft_cd(argv, argc, &mini);
	//printf("%s",ft_select2(mini.env[42]));
	//printf("%s",(argv[2]));
	//printf("%ld",ft_strlen(ft_select2(mini.env[42])));
	//printf("%ld",ft_strlen(argv[2]));
	//while(!ft_strnstr(mini.env[i],argv[2],ft_strlen(argv[2])))
		//i++;
	//if(strcmp(ft_select2(mini.env[i]),argv[2])!=0)
	//{
	//	i++;
	//	while(!ft_strnstr(mini.env[i],argv[2],ft_strlen(argv[2])))
		//	i++;
	//}
	//printf("%s",mini.env[i]);
	//printf("%d",strcmp(ft_select2(mini.env[i]),argv[2]));


	
	//if(argv[2] == mini.env[i] || argv[2] == ft_select2(mini.env[i]))
        //i++;
	//printf("%d",i);
	//printf("%d",i);
	//creat_export(&mini);
	//ft_export(argv,argc,&mini);

	//ft_env(&mini);
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n");
	//print_export(&mini);
	//realloc_env_be(&mini,argv[2]);
	//ft_get_add_env(&mini,argv[2]);
	//realloc_env(&mini,argv[2]);
	//realloc_export(&mini,argv[2]);
	//ft_unset(&mini ,argv[2]);
	//strlen_env(&mini,argv[2]);
	//printf("%d\n",strlen_env(&mini,argv[2]));
	//printf("%s\n\n\n",mini.env[strlen_env(&mini,argv[2])]);
	//ft_env(&mini);
	//ft_free(mini.env);
	//printf("%s\n",get_var_echo(argv[2]));
	//printf("%s\n",get_val_echo(argv[2]));
	printf("%s\n",ft_select(mini.env[1]));
	ft_select2(mini.env[i])
	while ((argv[2]) && ft_strcmp(get_var_echo(argv[2]), ft_select2(mini.env[i])))
			i++;
	printf("%s\n",ft_select1(mini.env[1]));
	return(0);
}

