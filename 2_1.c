#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    int max_char;       /* Максимальное значение для переменной типа char */
    max_char = 0;
    int max_short;      /* Максимальное значение для переменной типа short int */
    max_short = 0;
    long long int max_int;      /* чтобы поместилось максимальное значение типа (unsigned long int + 1) */
    max_int = 0;

    int i;      /* максимальное значение переменной целочисленного типа */
    int j;      /* минимальное значение переменной целочисленного типа */
    i = j = 0;

    printf("1. Данные берем из заголовочного файла <limits.h>\n");
    printf("Переменные типа \'signed char\' принимают значения в диапазоне от %d до %d\n", CHAR_MIN, CHAR_MAX);
    printf("Переменные типа \'unsigned char\' принимают значения в диапазоне от 0 до %d\n", UCHAR_MAX);
    printf("Переменные типа \'signed short int\' принимают значения в диапазоне от %d до %d\n", SHRT_MIN, SHRT_MAX);
    printf("Переменные типа \'unsigned short int\' принимают значения в диапазоне от 0 до %d\n", USHRT_MAX);
    printf("Переменные типа \'signed int\' принимают значения в диапазоне от %d до %d\n", INT_MIN, INT_MAX);
    printf("Переменные типа \'unsigned int\' принимают значения в диапазоне от 0 до %u\n", UINT_MAX);
    printf("Переменные типа \'signed long int\' принимают значения в диапазоне от %ld до %ld\n", LONG_MIN, LONG_MAX);
    printf("Переменные типа \'unsigned long int\' принимают значения в диапазоне от 0 до %lu\n", ULONG_MAX);
    printf("Переменные типа \'float\' принимают значения в диапазоне от %.0f до %f\n", FLT_MIN, FLT_MAX);
    printf("Переменные типа \'double\' принимают значения в диапазоне от %.0lf до %lf\n", DBL_MIN, DBL_MAX);
    printf("Переменные типа \'long double\' принимают значения в диапазоне от %.0Lf до %Lf\n", LDBL_MIN, LDBL_MAX);

    printf("\n2. Получаем данные путем прямого вычисления\n");
    /* Из файла limits.h получаем количество битов в char */
    /* printf("Размер переменной типа \'char\' %d бит\n", CHAR_BIT); */
    /* Для возведения в степень будем использовать функцию стандартной библиотеки pow()*/
    max_char = pow(2, CHAR_BIT);
    max_char = max_char - 1;
    printf("Переменные типа \'unsigned char\' принимают значения в диапазоне от 0 до %d\n", max_char);
    i = max_char / 2;   /* дробная часть отсекается */
    j = i - max_char;
    printf("Переменные типа \'signed char\' принимают значения в диапазоне от %d до %d\n", j, i);

    /* Согласно файлу limits.h тип short int имеет размер 16 бит */
    /* printf("Размер переменной типа \'short int\' %d бит\n", 16); */
    max_short = pow(2, 16);
    max_short = max_short - 1;
    printf("Переменные типа \'unsigned short int\' принимают значения в диапазоне от 0 до %d\n", max_short);
    i = max_short / 2;
    j = i - max_short;
    printf("Переменные типа \'signed short int\' принимают значения в диапазоне от %d до %d\n", j, i);

    /* Согласно файлу limits.h тип int имеет размер 32 бита */
    /* printf("Размер переменной типа \'int\' %d бит\n", 32); */
    max_int = pow(2, 32);
    max_int = max_int - 1;
    printf("Переменные типа \'unsigned int\' принимают значение от 0 до %lld\n", max_int);
    i = max_int / 2;
    j = i - max_int;
    printf("Переменные типа \'signed int\' принимают значения в диапазоне от %d до %d\n", j, i);

    return 0;
}
