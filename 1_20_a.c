#include <stdio.h>
#define TAB_SIZE 8
#define MAX_LINE 200
void detab(char s[]);
void entab(char s[]);
int get_line();

int main()
{
    char o[MAX_LINE];

    printf("Символы табуляции и пробелы \n");
    printf("Введите строку:\t1:\t2:\t3:\t4:\t5:\n");

    int l_length;
    while ((l_length = get_line(o, MAX_LINE)) > 0)
    {
        detab(o);
        printf(" - result programm.\n");

        entab(o);
        printf(" - result programm.\n");
    }
}

void detab(char s[])
{
    int column = 0;
    printf("Замена табов на пробелы.\n");
    int i = 0;
    while (s[i] != '\n')
    {
        if (s[i] == '\t')
        {
            do
            {
                putchar('.');
                ++column;
            } while (column % TAB_SIZE != 0);
        }
        else
        {

            putchar(s[i]);
            ++column;
        }
        i++;
    }
}
void entab(char s[])
{

    int column = 0;
    int spaces = 0;
    int i = 0;
    printf("Замена пробелов на табы.\n");
    while (s[i] != '\n')
    {
        if (s[i] == '\t')
            column += TAB_SIZE - (column % TAB_SIZE);
        else
            ++column;
        if (s[i] == ' ')
        {
            ++spaces;
            if (column % TAB_SIZE == 0)
            {
                printf("\\t");
                spaces = 0;
            }
        }
        else
        {
            while (spaces > 0)
            {
                putchar(' ');
                --spaces;
            }
            putchar(s[i]);
        }
        i++;
    }
}

int get_line(char s[], int max_line)
{
    int c, i;
    for (i = 0; i < max_line - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    s[i] = '\n';
    s[i+1] = '\0';
    return i;
}
