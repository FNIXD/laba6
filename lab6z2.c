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