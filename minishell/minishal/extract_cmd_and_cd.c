#include "header/minishell.h"

int size_cmd(char *str)
{
    int i;
    int size;

    size = 0;
    i = 0;
    while(str[i])
    {
        if(str[i] != '"' && str[i] != '\'')
            size ++;
        i++;
    }
    return size;
}

char *extract_cmd_and_cd(char *str)
{
    char *cmd;
    int i;
    int j;

    j = 0;
    i = 0;
    cmd = malloc(sizeof(char) * size_cmd(str) + 1);
    while(str[i])
    {
        if(str[i] == ' ' && str[i + 1] == ' ')
        {
            i++;
            continue;
        }
        if(str[i] != '"' && str[i] != '\'')
        {
            cmd[j] = str[i];
            j++; 
        }
        i++;
    }
    cmd[j] = 0;
    str[0] = 0;
    i = 0;
    j = 0;
    while(cmd[i])
    {
        if(cmd[i] == 'c' && cmd[i + 1]  == 'd' && cmd[i + 2] == ' ')
            i = i + 3;
        str[j] = cmd[i];
        i ++;
        j++;
    }
    str[j] = '\0';
    free(cmd);
    return (str);
}