#include <stdio.h>
/*#define MAX_LINE 1000*/

int get_line(char line[]/*, int lim*/);
void copy(char to[], char from[]);
int str_size(char s[]);

int main(){
	int len, c;
	int max;
	len = 1;
	char line[len];
	char longest[len];
	max = 0;

	while((c = getchar()) != EOF && (len = get_line(line/*, MAX_LINE)*/)) > 0)
		
		if (len > max){
			max = len;
			copy(longest, line);
			//printf("%s", longest);
		}
	if (max > 0)
		printf("%s", longest);
		
        return 0;
}

int get_line(char s[]/*, int lim*/){
	int c, i;
	for(i = 0;/* i < lim-1 &&*/ (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
                s[i] = c;
              	++i;
        }
	
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i;
	i = 0;

	while((to[i] = from[i]) != '\0')
		++i;
}

