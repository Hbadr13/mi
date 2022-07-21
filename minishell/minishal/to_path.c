
#include "header/minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((ss1[i] == s2[i]) && (i < n - 1) && ss1[i] != '\0' && ss2[i] != '\0')
		i++;
	return (ss1[i] - ss2[i]);
}

static	char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(needle);
	if (needle[i] == 0)
		return ((char *)haystack);
	while ((haystack[i]) && (i + l - 1) < len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(haystack + i, needle, l) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

char	*to_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "WINDOWPATH", ft_strlen(envp[i])))
			i++;
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
