# Лабораторная работа №6
## Задание 1. Напишите программу, которая проверяет является ли введенный год високосным.
```c
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
```
## Результат
```
Введите год: 2017
Остаток от деления на 4: 1
По упрощённому правилу (кратность 4): год 2017 не високосный
год 2017 не високосный

Введите год: 2020
Остаток от деления на 4: 0
По упрощённому правилу (кратность 4): год 2020 високосный
год 2020 високосный
```
## Задание 2. Напишите программу для вычислений значения функции F(x).
```c
/*
 *          | x^2 + 4x + 5,       при x <= 2
 *   F(x) = |
 *          | 1 / (x^2 + 4x + 5), при x > 2
 *
 * Контрольные примеры (рассчитаны вручную):
 * Ветвь x <= 2:
 * x = -2 -> 4 - 8 + 5   = 1
 * x = 0  -> 0 + 0 + 5   = 5
 * x = 2  -> 4 + 8 + 5   = 17
 * (граница, входит в первую ветвь)
 *
 * Ветвь x > 2:
 * x = 2.01 -> 1 / (4.0401 + 8.04 + 5) = 1 / 17.0801 = 0.058547   (сразу за границей)
 * x = 3    -> 1 / (9 + 12 + 5)        = 1/26         = 0.038462
 * x = 4    -> 1 / (16 + 16 + 5)       = 1/37         = 0.027027
 * x = 5    -> 1 / (25 + 20 + 5)       = 1/50         = 0.02
 *
 * Знаменатель x^2 + 4x + 5 = (x + 2)^2 + 1 всегда не меньше 1
 * (дискриминант 16 - 20 < 0, корней нет), поэтому деления на ноль нет.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double F(double x);

int main(void)
{
    double x;
    double result;

    setlocale(LC_ALL, ".UTF8");

    printf("Введите x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Ошибка: нужно ввести число.\n");
        return 1;
    }

    result = F(x);
    printf("F(%.2f) = %.2f\n", x, result);

    return 0;
}

double F(double x)
{
    double result;

    if (x <= 2)
        result = x * x + 4 * x + 5;
    else
        result = 1 / (x * x + 4 * x + 5);

    return result;
}
```
##Результат
```
Введите x: 2
F(2,00) = 17,00

Введите x: 4
F(4,00) = 0,03

Введите x: 1
F(1,00) = 10,00
```
## Выполнил 
Студент Еркимбеков Дмитрий бИД-261
