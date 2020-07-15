#include <stdio.h>

float to_fahr (float cels);

int main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = -10;
    upper = +10;
    step = 1;
    celsius = lower;
    printf("Celsius to Fahr.\n" );
    while (celsius <= upper) {
        printf("%3.0f\t%6.1f\n", celsius, to_fahr(celsius));
        celsius = celsius + step;
        }
}

float to_fahr(float cels){
	float fahr;
     fahr = (cels/(5.0/9.0))+32;
     return fahr;
}
