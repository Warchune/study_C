#include <stdio.h>

//Compiler version gcc  6.3.0

int main()
{
  int c,h=7;
  
  int center =(h/2);
  
  
  int str[h];
  /*Заполням строку*/
  for(int i=0;i<h;++i){
    str[i]='-';
  }
  /*Вставляем символы*/
  for(int i=0;i<h;++i){
    if(i<=center){
      str[center+i]='*';
      str[center-i]='*';
    }
    if(i>center){
      str[(h-1)-(i-center)]='*';
      str[i-center]='*';
    }
   
    for(int j=0;j<h;++j){   
      printf("%c",str[j]);
    }        
    putchar('\n'); 
    
     /*Сбрасываем символы в строке*/ 
     for(int i=0;i<h;++i){
      str[i]='-';
     }
  }
     
  return 0;
  
 }

  
 
 