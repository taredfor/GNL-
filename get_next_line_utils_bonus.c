#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (char *)(malloc(sizeof (char) * (ft_strlen(s1) + 1)));
	if (!mem)
		return (0);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (s1 == NULL)
		return (ft_strdup(s2));
	temp = (char *)malloc(sizeof(char) * (i + j +1));
	if (!temp)
		return (0);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*((unsigned char *)str + i) == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)(str + i));
	return (0);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*mem;
	size_t	i;

	mem = (char *)malloc(sizeof(char) * (n + 1));
	if (!mem)
		return (0);
	i = 0;
	while (i < n)
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
