# Проект Get Next line

*Ссылка на тесты:

[gnlTester](https://github.com/Tripouille/gnlTester)

*Команда для запуска:

make m = launch mandatory tests

 make b = launch bonus tests

make a = launch mandatory tests + bonus tests

[42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)

*Команда для запуска:

1 - cd 42TESTERS-GNL

2 - bash all_tests.sh or all_tests_with_bonus.sh

[GET NEXT LINE TESTER](https://github.com/Hellio404/Get_Next_Line_Tester)

*Команда для запуска:

1 - EDIT Makefile PATH
2 - bash run.sh


*MAIN for Leaks:

--1 - Проверка на Leaks

#include <stdio.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("get_next_line.c", O_RDONLY);
    char *line;
    int ret;

    ret = 1;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        printf("%d || %s\n", ret, line);
        free(line);
    }
    while(1);
    return (0);
}

--2 - Leaks a.out

*MAIN for Evaluate:

#include <stdio.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int    fd;
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

* MAIN from github

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

*Main for Bonus

#include <stdio.h>
#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int    fd1;
    int    fd2;
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



