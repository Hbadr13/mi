#include "header/minishell.h"
void printf_error(char *str)
{
    while (*str)
    {
        if (*str == '\\')
        {
            printf("minishell: no such file or directory:  %s\n",str);
            return;
        }
        str++;
    }
    printf("minishell: command not found:  %s\n",str);
}
int        chack_if_ecpace_in_inpt(char *str)
{
    int i;
    int vlag1;
    int vlag2;

    i = 0;
    vlag1 = 0;
    vlag2 = 0;
    while (str[i])
    {
        if(str[i] == ' ')
            vlag1 = 1;
        if (str[i] == '\'' || str[i] == '"')
            vlag2 = 1;
        i++;
    }
    if(vlag1 == 1 && vlag2 == 1)
        return (printf_error(str),-1);
    return (0);
}


int mutiline_commands(char *str)
{
        int k = 0;
        int j = 0;
        int i = 0;
        while(str[i])
        {
            if(str[i] == '"')
                k++;
            if(str[i] == '\'')
                j++;
            i++;
        }
        if(k == 0 && j == 0)
            return 0;
        if((k % 2 != 0 || j % 2 != 0))
            return(printf("problem syntax...\n"),-1);
        k = j = i = 0;
        while(str[i])
        {        
            if(str[i] == '\'')
                k = i;
            if(str[i] == '\'' && j == 0)
                j = i;
            i++;
        }
        i = 0;
        int s = 0, w = 0;
        while(str[i])
        {
            if(str[i] == '"' && i < j)
                s = 1;
            if(str[i] == '"' && i > k)
                w = 1;
            i++;
        }
        if(s == 1 && w == 1)
            return(printf("problem syntax...\n"),-1);
        // if(chack_if_ecpace_in_inpt(str) == -1)
        //     return(-1);
        return 0;
}
