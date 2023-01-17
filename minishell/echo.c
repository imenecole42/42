#include "minishell.h"
int ft_check(char *argv)
{
	int i=1;
	if(argv[0]=='-')
	{
		while(argv[i]=='n')
			i++;
		if(argv[i]=='\0')
			return(1);
	}
	return(0);
}

int ft_echo(char **argv,int argc)
{

	int i=1;
	int j=0;

	if(i < argc - 1)
		i++;
	while(argv[i][j] && i <= argc - 1)
	{
		write(1,&argv[i][j],1);
		j++;
	}
	i--;
	if(!ft_check(argv[i]))
		write(1,"\n",1);
	return(0);
}


