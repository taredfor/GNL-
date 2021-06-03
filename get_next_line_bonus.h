#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "stdlib.h"
# include "unistd.h"

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strndup(const char *str, size_t n);
int		ft_reminder(char **reminder, char **line, int n);
char	*ft_strdup(const char *s1);
char	*ft_new_reminder(char **reminder, char **buffer);

#endif