#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
        int     fd[2], receiver;
        pid_t   childpid;
        char    string[] = "Hello, world!\n";
        char    readbuffer[80];
        pid_t   pid_check;


        pipe(fd);

        pid_check = getpid(); printf ("I am the parent pid: %d \n", pid_check);

        childpid = fork();

        if(childpid == -1) {perror("fork");}


        if(childpid == 0)
        {
                pid_check = getpid(); printf ("[c] I am the child pid: %d \n", pid_check);

                /* Child process closes up input side of pipe */
                close(fd[0]);
                printf("[c] I am sending %s into the pipe", string);
                /* Send "string" through the output side of pipe */
                write(fd[1], string, (strlen(string)+1));



                exit(0);
        }
        else
        {
                pid_check = getpid(); printf ("I am the parent pid again: %d \n", pid_check);

                /* Parent process closes up output side of pipe */
                close(fd[1]);
                printf ("I closed the writing side and I am reading: \n");
                /* Read in a string from the pipe */
                receiver = read(fd[0], readbuffer, sizeof(readbuffer));
                printf("Received string: %s", readbuffer);
        }
        exit(1);
      return(0);
}
