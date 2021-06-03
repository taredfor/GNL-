#include <stdio.h>
#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int	fd1;
	int	fd2;
    char *line;

    fd1 = open("get_next_line.c", O_RDONLY);
	fd2 = open("get_next_line_bonus.c", O_RDONLY);

	printf("%d | %s\n", get_next_line(fd1, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd2, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd1, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd2, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd1, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd2, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd1, &line), line);
	free(line);

	printf("%d | %s\n", get_next_line(fd2, &line), line);
	free(line);
}
