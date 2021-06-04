#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
int display(char strings[100][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        puts(strings[i]);
    }

    return 0;
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
        } while (strcmp(strings[i], pivot)>0);
         
         do
         {
             j--;
         } while (strcmp(strings[j],pivot)<0);
         if( i < j )
         {
            strcpy(temp,strings[i]);
            strcpy(strings[i],strings[j]);
            strcpy(strings[j],temp);
         }    
    }
        strcpy(temp,strings[l]);
        strcpy(strings[l],strings[j]);
       strcpy(strings[j],temp);
            
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

int main()
{
    char str[100][100]={{""},{""},{"aa"},{"uol"}};
 quicksort(str,0,3);
    display(str,4);
    
   




}