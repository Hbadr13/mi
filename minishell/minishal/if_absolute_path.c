#include"header/minishell.h"

int  if_absolute_path(char *str)
{
    int i;
    i = 0;
    int j = 0;
    if((str[0] == '~' && str[1] == '\0') || ft_strncmp(str, "cd",2) == 0)
    {
         chdir("/home/hbadr");
         return 1;
    }
    
    while(str[i])
    {
        if(str[i] == '/')
            j++;
        i++;
    }
    if(j == 0)
        return 0;
    if(access(str,F_OK) == -1)
    {
        printf("minisell : no such file or directory: %s\n",str);
        return 1;
    }
    chdir(str);    
    return 1;
}