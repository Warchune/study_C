#include <stdio.h>
#include <math.h>
int fact(int n);

//Compiler version gcc  6.3.0

int main()
{
  int a,b,n,i,j;
  unsigned long long s=0;
  
  printf("Вычисление выражения (a+b) в степени n\n");
  printf("Введите a:\n");
  scanf("%d",&a);
  printf("Введите b:\n");
  scanf("%d",&b);
  printf("В степень:\n");
  scanf("%d",&n);
  
  for(i=n,j=0;i>=0,j<=n;i--,j++){
     s=s+fact(n)/(fact(j)*fact(n-j))*pow(a,i)*pow(b,j);
  }
    
  printf("Результат:%d\n",s);
  return 0;
}

int fact(int n){
  if(n<=1)
    return 1;
  else
    return fact(n-1)*n;
}