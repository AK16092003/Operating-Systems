#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
        pid_t pid;
        pid = fork();

        if(pid < 0)
        {
                printf("fork failed \n");


        }
        else if(pid == 0)
        {
                printf("I am the child \n");
        }
        else if(pid > 0)
        {
                printf("I am the parent\n");
                printf("%d\n" , pid);
                wait(NULL);
                printf("Child complete\n\n");
        }

        return 0;
}
