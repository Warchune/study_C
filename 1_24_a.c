#include <stdio.h>

#define MAXLINE 1000

int getstr(char s[], int maxline);

int main(void)
{
    char line[MAXLINE];
    int len;    /* длина строки */
    int i;      /* индекс элемента строки */
    int parentheses;    /* круглые скобки */
    int braces;         /* фигурные скобки */
    int brackets;       /* квадратные скобки */
    int quotes;         /* кавычки */
    int single_quotes;  /* одинарные кавычки */
    int comment;        /* комментарий */
    int escape;         /* эскейп-последовательность */

    len = 0;
    parentheses = 0;
    braces = 0;
    brackets = 0;
    quotes = 0;
    single_quotes = 0;
    comment = 0;
    escape = 0;

    while ((len = getstr(line, MAXLINE)) > 0)
    {
        i = 0;
        while (i < len)
        {
            if (line[i] == '(')
                ++parentheses;
            if (line[i] == ')')
                --parentheses;

            if (line[i] == '{')
                ++braces;
            if (line[i] == '}')
                --braces;

            if (line[i] == '[')
                ++brackets;
            if (line[i] == ']')
                --brackets;

            if (line[i] == '"')
                ++quotes;

            if (line[i] == '\'')
                ++single_quotes;

            if (line[i] == '/' && line[i + 1] == '*')
                ++comment;

            if (line[i] == '*' && line[i + 1] == '/')
                --comment;

            /* Если за символом '\\' следует
             * либо 'n', либо 't', либо 'b', либо '0', либо '\'', либо '\"',
             * тоесть образуется эскейп-последовательность,
             * сигнализируем об отсутствии ошибок */
            if (line[i] == '\\')
            {
                if (line[i + 1] == 'n' ||
                        line[i + 1] == 't' ||
                        line[i + 1] == '\'' ||
                        line[i + 1] == '\"' ||
                        line[i + 1] == 'b' ||
                        line[i + 1] == '0')
                escape = 0;

                /* Если за символом '\\' следует символ '\\',
                 * что тоже образует эскейп-последовательность,
                 * мы сигнализируем об отсутствии ошибок,
                 * но увеличиваем индекс массива дабы повторно
                 * не обрабатывать второй символ '\\' */
                else if (line [i + 1] == '\\')
                {
                        escape = 0;
                        ++i;
                }

                else
                        ++escape;
            }
            ++i;
        }
    }

    /* Подводим итоги.
     * Поскольку скобки открываются и закрываются, то
     * если parentheses != 0, braces != 0, brackets != 0
     * значит существует соответствующая несбалансированность*/
    if (parentheses != 0)
        printf("Несбалансированность круглых скобок.\n");
    if (braces != 0)
        printf("Несбалансированность фигурных скобок.\n");
    if (brackets != 0)
        printf("Несбалансированность квадратных скобок.\n");

    /* Число кавычек должно быть парным */
    if ((quotes % 2) != 0)
        printf("Несбалансированность кавычек.\n");
    if ((single_quotes % 2) != 0)
        printf("Несбалансированность одинарных кавычек.\n");
    if (comment != 0)
        printf("Несбалансированность комментариев.\n");
    if (escape > 0)
        printf("%d синтаксических ошибок в эскейп-последовательностях\n", escape);
    if (parentheses == 0 &&
            braces == 0 &&
            brackets == 0 &&
            (quotes % 2) == 0 &&
            (single_quotes % 2) == 0 &&
            comment == 0 &&
            escape == 0)
        printf("Элементарные синтаксические ошибки отсутствуют.\n");

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

void finde_sumbol(char s, int c){
    if (s == c)
        ++parentheses;
    if (s == c)
        --parentheses;
}
