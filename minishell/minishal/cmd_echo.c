#include "header/minishell.h" 
int cmd_echo(char *str)
{
    char **tab;

    tab = ft_split(str,' ');
    if (!tab[0])
        return 1;
    if(mutiline_commands(tab[0]) == -1)
        return 1;
    int i = 0;
    int j = 0;
    char *ptr = "echo";
    while(tab[0][i])
    {
        if(tab[0][i] == ptr[j])
            j++;
        i++;
    }
    if(j != 4)
        return(0);
    i = 1;
    while(tab[i])
        printf("-%s ",tab[i++]);
    printf("\n");
    return 1;
}