#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int  fd, ret, line_count;
    char *line;

    line_count = 1;
    ret = 0;
    line = NULL;
    if (argc == 2)
    {
        fd = open(argv[1],  O_RDONLY);
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            printf(" \n [ Return: %d ] | Прочитана строка #%d => %s\n", ret, line_count, line);
   line_count++;
   free(line);
  }
  printf(" \n [ Return: %d ] Прочитана строка #%d: %s\n", ret, line_count++, line);
  printf("\n");
  if (ret == -1)
   printf("-----------\n Произошла ошибка\n");
  else if (ret == 0)
  {
   printf("-----------\n Достигнут EOF\n");
   free(line);
  }
  close(fd);
 }
 if (argc == 1)
 {
  while ((ret = get_next_line(0, &line)) > 0)
  {
   printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
   line_count++;
  }
  if (ret == -1)
   printf("\n Произошла ошибка\n");
  else if (ret == 0)
   printf("\n Достигнут EOF\n");
  close(fd);
 }
 return (0);
}