#include"header/minishell.h"
char *find_path()
{
        char *path;
        int i;
        int j;
        j = 0;
        i = 0;
        path = getcwd(NULL, 0);
        while(path[i])
        {
                if(path[i] == '/')
                        j = i;
                i++;
        }
        if(ft_strncmp(path,"/",2) == 0)          
                j = 0;
        else
                path = ft_strjoin(path + j + 1,"");
        path = ft_strjoin("\x1B[31m➜ \x1B[33m", path);
        path = ft_strjoin(path, " \x1B[0m");
        return path;

}
void handler (int status)
{
        write(1, "\n", 1);
        rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
}
int main(int ac , char **argv, char **envp)
{
        t_mini cont;
        char  **list;
        char *inpt;
        char *str;
        int i = 0;
        int id;
        char *path;
        while (2)
        {
	        cont.path = to_path(envp);
	        cont.tab_path = ft_split(cont.path, ':');
                path = find_path();
                signal(SIGINT,handler);
                inpt = readline(path);
                if(!inpt || strcmp("exit",inpt) == 0)
                        printf("\n") ,exit(0);
                if(inpt[0] == '\0')
                        continue;
                // if(cmd_echo(inpt) == 1)
                //          continue ;
                if(mutiline_commands(inpt) == -1)
                         continue;
                 inpt = extract_cmd_and_cd(inpt);
                if(!inpt[0])
                        continue;
                if(if_absolute_path(inpt) == 1)
                        continue;
                cont.cmd_list = ft_split(inpt, ' ');
                if(!cont.cmd_list[0])
                        continue;
                str = comd_existe(cont, cont.cmd_list[0]);   
                if(!str)
                        printf("minishell: comd not found : %s\n",inpt);
                else
                {
                        id = fork();
                        if(id == 0)
                                execve(str,cont.cmd_list,envp);
                        wait(NULL);
                }
                free(inpt);
        }
        return 0;
}
