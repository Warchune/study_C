
#include <stdio.h>
#define TAB 8
#define LEN 5

void print_line(int symv);
int search_space(int symv);
int search_newsymv(int symv);
char line[LEN];

int main()
{
    int c, symv;
    
    symv=0;
    while((c=getchar()) != EOF)
    {
        line[symv]=c;
        if(c=='\t')
        {
            line[symv]=' ';
            for(symv++; symv<LEN && symv%TAB != 0; symv++)
                line[symv]=' ';
            if(symv>=LEN)
                print_line(symv);                
        }
        if(c=='\n')
        {
            print_line(symv);
            symv=0;
        }
        else
        {
            if(symv++>=LEN)
            {
                symv=search_space(symv);
                print_line(symv);
                symv=search_newsymv(symv);
            }
        }
    }
    return 0;
}

/*печать строки*/
void print_line(int symv)
{
    int i;
    for(i=0; i<symv; i++)
        putchar(line[i]);
    if(symv>0)
        putchar('\n');
}

/*поиск пробела*/
int search_space(int symv)
{
    while(line[symv] !=' ' && symv>0)
        symv--;
    if(symv==0)
        return LEN;
    else
        return symv++;
}

/*поиск места размещения симdола
 * в новой строке*/
int search_newsymv(int symv)
{
    int i, j;
    if(symv<=0 || symv>=LEN)
        return 0;
    else
    {
        i=0;
        for(j=symv++; j<LEN; j++)
        {
            line[i] = line[j];
            i++;
        }
        return i;
    }
}
