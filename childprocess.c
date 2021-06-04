#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    printf("Anmol Agarwal - 190953140\n");
    int status;
    int n = argc;
    pid_t pid1 = fork();
   

    if (pid1 == 0)
    { char temp[100];
        printf("I am a child process I will sort the array\n");
        
        for( int i = 1 ; i <n;i++)
        {
            for( int j = i +1;  j <n ; j ++)
            {   
                if(strcmp(argv[i],argv[j])>0)
                {
                    strcpy(temp,argv[i]);
                    strcpy(argv[i],argv[j]);
                    strcpy(argv[j],temp);
                    
                sleep(0.1);
                }
            }
        }
         for (int i = 1; i < n; i++)
        {
            printf(" \n");
             puts(argv[i]);
        }

       
    
       
        
    }

    else if (pid1 > 1)
    {  wait(&status);
        printf("I am a Parent process I will show unsorted strings\n");
         for (int i = 1; i < n; i++)
        {
            printf(" \n");
             puts(argv[i]);
        }
       
      
    }

    else
    {
        printf("Error Occured");
        exit(1);
    }


    return 0;
}