#include <stdio.h>
/*Гистограмма ASCII коды от 0 до 256 */

int main(){
	int c;
	int sym[256];
	for(int i = 0; i < 256; ++i)
		sym[i] = 0;

	while((c = getchar()) != EOF){
		++sym[c];
	}

	for(int i = 0; i < 256; i++)
		if(sym[i] > 0){
			if(i >= 32)
				printf("Симв '%c' - ", i);
			else
				printf("Код '%2d' - ", i);
			for(int j = 0; j < sym[i]; ++j)
				putchar('|');
			putchar('\n');
			
		}
}
