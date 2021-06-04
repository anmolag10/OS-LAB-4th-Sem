#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/wait.h>
#define BUFFLEN 10
int main()
{
    char buffer[BUFFLEN + 1];
    pid_t pid1;
    int status;
    pid1 = fork();
    if (pid1 == 0)
    {
        strncpy(buffer, "Child\n", BUFFLEN);
        buffer[BUFFLEN] = '\0';
    }

    else if (pid1 > 0)
    {
        strncpy(buffer, "Parent\n", BUFFLEN);
        buffer[BUFFLEN] = '\0';
        wait(&status);
        
        
    }
    else
    {
        printf("Error");
    }
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        write(1, buffer, strlen(buffer)) ;
    }
    wait(&status);
    return 0;
}
