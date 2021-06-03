#include <stdio.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int	fd;
    char *line;
    int n;

    n = 1;
    fd = open("text.txt", O_RDONLY);
	while (n > 0)
	{
		n = (get_next_line(fd, &line));
		printf("%s\n\n", line);
		if (!n)
			break;
		free(line);
	}
	while (1);
}
