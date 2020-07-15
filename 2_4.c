#include <stdio.h>

void my_squeeze(char s1[], char s2[])

int main(){
    char s1[] = "abc", s2[] = "b";
    printf("%s, %s\n", s1, s2);
    my_squeeze(s1, s2);
    return 0;
}

void my_squeeze(char s1[], char s2[]){
    int i, j;
    int sym[256];

    for(int i = 0; i < 256; ++i)
        sym[i] = 0;

    i = 0;
    while(s2[i++] != '\0'){
        ++sym[(int)s2[i]];
    }

    for (i = j = 0; s1[i] != '\0'; i++){
        printf("%d - %c, %d\n", (int)s1[i], s1[i], sym[(int)s1[i]]);
        if (sym[(int)s1[i]] == 0){
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';

    printf("%s\n", s1);
}
