#include <stdio.h>

void printEssay(const char essay[])
{
    printf("Essay: \n");
    printf("%s\n", essay);    
}

void printResult(const char essay[], int pos)
{
    printf("\nPattern found at index %d\n", pos);
    printf("%s\n", essay);
    for (int i=0; i<pos; i++)
    {
        printf(" ");
    }
    if (pos != -1 )
    {
        printf("^\n");
    }    
}