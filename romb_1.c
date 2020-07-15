#include <stdio.h>
#define N 2
void print_space(int);
void print_line(int, int);
int  my_atoi(char s[]);

int main(){
    int size, i = 0, n, c;
    char size_str[N];

    while((c = getchar()) != '\n'){
        size_str[i] = c;
        i++;
    }

    size = my_atoi(size_str);
    n = size / 2;
    for (i = 0; i <= n; i++){
        print_line(i, n);
    }
    for (i = n - 1; i >= 0; i--){
        print_line(i, n);
    }
}

void print_space(int count){
    int i;
    for(i = 0; i <= count; i++){
        printf("_");
    }
}

void print_line(int i, int n){
    print_space(n - i - 1); // вывод пробелов до знака
    printf("*");
    if(i > 0){
        print_space(2 * (i + 1) - 4);  // вывод пробелов между знаками
        printf("*");
    }
    print_space(n - i - 1);    // вывод пробелов после знака
    printf("\n");
}

int my_atoi(char s[]){
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++){
        n = 10 * n + (s[i] - '0');
    }
    return n;
}