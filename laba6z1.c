#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int remainder_by_4(int year);
int is_leap_year(int year);

int main(void)
{
    int year;
    int faw;
    int leap;

    setlocale(LC_CTYPE, ".UTF8");

    printf("Введите год: ");
    if (scanf("%d", &year) != 1 || year <= 0)
    {
        printf("Ошибка: нужно ввести целое положительное число.\n");
        return 1;
    }

 
    faw = remainder_by_4(year);
    printf("Остаток от деления на 4: %d\n", faw);
    if (faw == 0)
        printf("По упрощённому правилу (кратность 4): год %d високосный\n", year);
    else
        printf("По упрощённому правилу (кратность 4): год %d не високосный\n", year);

    leap = is_leap_year(year);
    if (leap)
        printf("год %d високосный\n", year);
    else
        printf("год %d не високосный\n", year);

    return 0;
}

int remainder_by_4(int year)
{
    int faw;

    faw = year % 4;

    return faw;
}

int is_leap_year(int year)
{
    int leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    return leap;
}