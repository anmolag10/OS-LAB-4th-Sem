#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/wait.h>
#include<stdlib.h>
int main()
{
   printf("Anmol Agarwal -190953140");

    pid_t pid1 = fork();
    
    
    if(pid1==0)
    {
         printf("I am a child process\n");
         printf("My Parent ID: %d\n",getppid());
         printf("My ID: %d\n", getpid());
    } 

 
    else if( pid1>1)
    {
      printf("I am a Parent process\n");
         printf("My Parent ID: %d\n",getppid());
         printf("My ID: %d\n", getpid());
    }

    else
    {   
        printf("Error Occured");
        exit(1);
    }
    
       printf("\n \n");
    return 0;
}
