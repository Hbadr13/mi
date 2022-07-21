#ifndef MINISHELL_H
# define PIPEX_H MINISHELL_H

#include <unistd.h>
#include <stdio.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
#include <readline/readline.h>
#include "/usr/include/readline/readline.h"
#include<stdlib.h>
typedef struct minishell {
    char **argv;
    char **envp;
    char **cmd_list;
    char *path;
    char **tab_path;
}t_mini;
int main(int ac, char **argv, char **envp);
char	*comd_existe(t_mini cont, char *cmd);
char	*to_path(char **envp);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int  if_absolute_path(char *str);
char	*ft_strjoin(char  *s1, char  *s2);

//mutiline_commands
int mutiline_commands(char *str);
char *extract_cmd_and_cd(char *str);

//libft
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// echo
int cmd_echo(char *str);
#endif
