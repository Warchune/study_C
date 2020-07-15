#include <stdio.h>
#define MAXLINE 5
#define LONGLIN 10

int my_getline(char line[], int maxline);

int main() {
    int len; //длина текущей строки
    char line[MAXLINE]; //текущая строка
    while((len=my_getline(line, LONGLIN))>0)
        if((len-1)>5)
            printf("Эта строка больше 5 символов: %s\n", line);
    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;
    for(i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++)
        s[i]=c;
    if(c=='\n')
    {
        s[i]=c;
        i++;
    }
    s[i] = '\0';
    return i;
}
