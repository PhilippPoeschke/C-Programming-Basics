#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char const *argv[]) {

  int fd1[2];
  int fd2[2];

  char fixed_str[] = "forgeeks.org";
  char input_str[100];
  pid_t p;

      // We use two pipes
      // First pipe to send input string from parent
      // Second pipe to send concatenated string from child

  if (pipe(fd1)==-1)
  {
    fprintf(stderr, "Pipe 1 failed");
    return 1;
  }
  if (pipe(fd2)==-1)
  {
    fprintf(stderr, "Pipe 2 failed");
    return 1;
  }

  scanf("%s", input_str);
  p = fork();

  if (p < 0)
  {
    fprintf(stderr, "fork failed");
    return 1;
  }

  // Parent process
  else if (p > 0)
  {
    char concat_str[100];

    close(fd1[0]); // close reading end of first pipe

    write(fd1[1], input_str, strlen(input_str)+1);
    close(fd1[1]);

    wait(NULL);

    close(fd2[1]); // close writing end of first pipe

    read(fd2[0], concat_str, 100);
    printf("concatenated string %s\n", concat_str );

    close(fd2[0]);
  }
  else
  {
    close(fd1[1]);

    char concat_str[100];
    read(fd1[0], concat_str, 100);

    int k = strlen(concat_str);
    int i = 0;
    while (i < strlen(fixed_str))
    {
      concat_str[k++] = fixed_str[i];
      i++;}
      concat_str[k] = '\0';

      close(fd1[0]);
      close(fd2[0]);

      write(fd2[1],concat_str, strlen(concat_str)+1);
      close(fd2[1]);

      exit(0);

  }
  return 0;
}
