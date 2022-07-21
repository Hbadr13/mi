
#include "header/minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}	
	p[i] = '\0';
	return (p);
}

char	*comd_existe(t_mini cont, char *cmd)
{
	char	*add_backslash;
	char	*path;
	//printf("%s\n",cmd);
	if (cmd[0] == '\\')
			cmd = cmd + 1;
	
	while (*cont.tab_path)
	{
		add_backslash = ft_strjoin(*cont.tab_path, "/");
		path = ft_strjoin(add_backslash, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		free(add_backslash);
		cont.tab_path++;
	}
	return (NULL);
}
