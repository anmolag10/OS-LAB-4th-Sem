#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
int display(char strings[100][100], int n)
{
    for (int i = 0; i <= n; i++)
    {
        puts(strings[i]);
    }

    return 0;
}
int bubblesort(char strings[1000][1000], int n)
{
    char temp[100];

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
}
int partions(char strings[100][100], int l, int h)
{
    int i = l;
    int j = h;
    char pivot[100];
    char temp[100];
    strcpy(pivot, strings[0]);
    while (i < j)
    {
        do
        {
            i++;
        } while (strcmp(strings[i], pivot) > 0);

        do
        {
            j--;
        } while (strcmp(strings[j], pivot) < 0);
        if (i < j)
        {
            strcpy(temp, strings[i]);
            strcpy(strings[i], strings[j]);
            strcpy(strings[j], temp);
        }
    }
    strcpy(temp, strings[l]);
    strcpy(strings[l], strings[j]);
    strcpy(strings[j], temp);

    return j;
}
int quicksort(char strings[100][100], int l, int h)
{
    if (l < h)
    {
        int j = partions(strings, l, h);
        quicksort(strings, l, j);
        quicksort(strings, j + 1, h);
    }
}
int main(int argc, char *argv[])
{

    printf("Anmol Agarwal - 190953140\n");
    int status;
    int n;
    printf("Enter the no. of strings:\n");
    scanf("%d", &n);
    char strings[100][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", strings[i]);
    }
   
    pid_t pid1 = fork();

    if (pid1 == 0)
    {
        pid_t pid2 = fork();

        if (pid2 == 0)
        {
            printf("I am child 2 and I am using quicksort\n");
            quicksort(strings, 0, n);
            printf("Exiting Child 2\n");
             kill(getppid(), SIGKILL);
            printf("Sorted Array Using QuickSort\n");
            display(strings,n);
           
        }

        else if (pid2 > 0)
        {
            printf("I am child 1 and I am using bubblesort\n");
            while (1)
            {
            }
            printf("Exiting Child1");
            kill(pid2, SIGKILL);
            printf("Sorted Array Using Bubble Sort\n");
            display(strings,n);
     
        }

        else
        {
            printf("Couldnt Fork the process");
        }
    }

    else if (pid1 > 1)
    {
       wait(&status);
        printf("\nI am the parent I am Exiting \n");
    }
    else
    {
        printf("Error Occured");
        exit(1);
    }
}
