#include <stdio.h>
#define IN 1
#define OUT 0

int main(){
	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF){
		putchar(c);
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
	    	        putchar('\n');
		}
		else if (state == OUT){
			
			state = IN;
		}
	}
}
