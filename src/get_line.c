#include <stdio.h>

int get_line(char line[], int lim)
{
    int i = 0, c;
    while (lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
        --lim;
    }
    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

void read_pattern_from_stdio(char pattern[], int max)
{
    printf("Look for pattern: ");
    int num_char = get_line(pattern, max);
    pattern[num_char-1]='\0';
}