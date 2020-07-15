#include <stdio.h>

#define MAXLINE 1000

int getstr(char s[], int maxline);

int main(void)
{
    char line[MAXLINE];
    int len;    /* длина строки */
    int i;      /* индекс элемента строки */
    int in_comment;     /* 1 - находимся в комментарии; 0 - вне комментария */
    int in_quote;       /* 1 - находимся в кавычках; 0 - вне кавычек */

    len = 0;
    in_comment = 0;
    in_quote = 0;

    while ((len = getstr(line, MAXLINE)) > 0)
    {
        i = 0;
        while (i < len)
        {
            if (line[i] == '"')
                in_quote = 1;

            if (in_quote != 1)  /* мы вне строковых констант */
            {
                if (line[i] == '/' && line[i + 1] == '*')
                {
                    in_comment = 1;
                    i = i + 2;
                }

                if (line[i] == '*' && line[i + 1] == '/')
                {
                    in_comment = 0;
                    i = i + 2;
                }

                if (in_comment == 1)    /* мы внутри комментария */
                    ++i;

                else
                {
                    printf("%c", line[i]);
                    ++i;
                }
            }

            else
            {
                printf("%c", line[i]);
                ++i;
            }
        }
    }

    return 0;
}

int getstr(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;

}
