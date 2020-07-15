#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000    /* максимальный размер вводимой строки */

int getstr(char line[], int maxline);
int htoi(char line[]);

int main(void)
{
 int len = 0;
 int number = 0;
 char line[MAXLINE]; /* текущая строка */

 while ((len = getstr(line, MAXLINE)) > 0)
 {
  number = htoi(line);
  printf("Преобразует в число %d\n", number);
  number = 0;
 }

 return 0;
}

/* getline: читает строку в s, возвращает длину */
int getstr(char s[], int lim)
{
 int c, i;

 for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  s[i] = c;
 if (c == '\n')
 {
  s[i] = c;
  ++i;
 }
 s[i] = '\0';        /* в конец строки дописывам "0" */
 return i;   /* функция возвращает длину строки */
}

/* htoi: преобразует s в целое */
int htoi(char s[])
{
 int i, n, hexdigit;

 n = i = hexdigit = 0;

 if (s[i] == '0')
 {
  ++i;
  if (s[i] == 'x' || s[i] == 'X')
   ++i;
 }
 else {
  printf("Число не является шестнадцатеричным\n");
  return 0;
 }

 while (s[i] != '\n')
 {
  if (isdigit(s[i]) == 1) /* проверка, является ли символ цифрой */
   hexdigit = s[i] - '0';

  else if (s[i] >= 'a' && s[i] <= 'f')
   hexdigit = s[i] - 'a' + 10;

  else if (s[i] >= 'A' && s[i] <= 'F')
   hexdigit = s[i] - 'A' + 10;

  n = n * 16 + hexdigit;
  ++i;
 }
 
 return n;
}
