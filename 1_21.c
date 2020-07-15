#include <stdio.h>
#define TAB 8

int main()
{
    int c, ntab, nspace, symv;

    symv=1;
    ntab=0;//табуляции
    nspace=0;//пробелы
    while((c=getchar()) != EOF)
    {
        symv++;
        if(c==' ')
        {
            if(symv%TAB==0)
            {
                ntab++;
                nspace=0;
            }
            else
                nspace++;
        }
        else
        {
            while(ntab>0)
            {
                putchar('\t');
                ntab--;
            }
            if(c=='\t')
            {
                nspace=0;
                putchar('\t');
                symv=symv+(TAB-(symv%TAB));
            }
            else
            {
                while(nspace>0)
                {
                    putchar(' ');
                    nspace--;
                }
                putchar(c);
                if(c=='\n')
                {
                    symv=0;
                    ntab=0;
                    nspace=0;
                }
            }
        }
    }
    return 0;
}