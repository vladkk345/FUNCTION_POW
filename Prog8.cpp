// Prog8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>

double power(double n, int p); // определение функции

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, xpow;
    int exp;

    printf("Введите число и положительную целую степень,");
    printf("в которую\nчисло будет возведено. Для завершения программы");
    printf(" введите q.\n");

    while (scanf_s("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x, exp); // вызов функции
        if (x > 0 && exp >= 0)
        {
            printf("%.1lf в степени %d равно %.1lf\n", x, exp, xpow);
        }
        
        if (x > 0 && exp < 0)
        {
            printf("%.1lf в степени %d равно %.5lf\n", x, exp, xpow);
        }

        printf("Введите следующую пару чисел или q для завершения.\n");
    }
    printf("Надеемся, что вы оценили это упражнение -- до свидания!\n");

    return 0;
}

double power(double n, int p) // определение функции
{
    double pow = 1, res = 0;
    int i, j;

    for (i = 1; i <= p; i++)
    {
        pow *= n;
    }
       
    if (p < 0)
    {
        p = -p;
        for (j = 1; j <= p; j++)
        {
            pow *= n;
        }
        res = 1 / pow;
        return res;
    }
    
    if (n == 0 && p == 0)
    {
        printf("Результат возведения 0 в степень 0 не определен. По умолчанию 1\n");
    }
    if (n == 0 && p > 0)
    {
        printf("Результат возведения 0 в любую степень не определен. По умолчанию 0\n");
    }
    return pow; // возвратить значение pow

}