#include <stdio.h>
#include <math.h>
#include <locale.h>
// Функция для вычисления arctg(x) для x > 1 с помощью ряда Тейлора
double arctg_large_x(double x, double eps) {
    double term = -1.0 / x;        // первый член ряда (n=0): -1/x
    double sum = term;             // начальная сумма
    int n = 0;                     // номер текущего члена
    double x_sqr = x * x;          // x^2 для рекуррентной формулы

    // Вычисляем члены ряда пока их модуль больше точности
    while (fabs(term) >= eps) {
        n++;
        // Рекуррентная формула: term_n = term_(n-1) * (-1) * (2n-1)/((2n+1)*x^2)
        term *= -1.0 * (2 * n - 1) / ((2 * n + 1) * x_sqr);
        sum += term;
    }

    // acos(0) = π/2
    return acos(0.0) + sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    double x_start, x_end, dx, epsilon;

    // Ввод параметров
    printf("Введите начальное значение x (> 1): ");
    scanf_s("%lf", &x_start);
    printf("Введите конечное значение x (> 1): ");
    scanf_s("%lf", &x_end);
    printf("Введите шаг dx: ");
    scanf_s("%lf", &dx);
    printf("Введите точность epsilon: ");
    scanf_s("%lf", &epsilon);

    // Проверка корректности введенных данных
    if (dx <= 0) {
        printf("Ошибка: шаг dx должен быть положительным!\n");
        return 1;
    }

    if (epsilon <= 0) {
        printf("Ошибка: точность epsilon должна быть положительной!\n");
        return 1;
    }

    if (x_start <= 1 || x_end <= 1) {
        printf("Ошибка: x должен быть больше 1\n");
        return 1;
    }

    // Вывод заголовка таблицы
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("|        x |   Ряд Тейлора | Точное значение |   Членов |\n");
    printf("------------------------------------------------------------\n");

    // Вычисление и вывод значений функции
    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double term = -1.0 / x;        // текущий член ряда: -1/x
        double sum = term;             // текущая сумма
        int n = 0;                     // номер текущего члена
        int count = 1;                 // счетчик членов
        double x_sqr = x * x;          // x^2

        // Вычисление суммы ряда до достижения точности
        while (fabs(term) >= epsilon) {
            n++;
            // Рекуррентная формула: term_n = term_(n-1) * (-1) * (2n-1)/((2n+1)*x^2)
            term *= -1.0 * (2 * n - 1) / ((2 * n + 1) * x_sqr);
            sum += term;
            count++;
        }

        // Точное значение функции
        double exact = atan(x);
        double series_value = acos(0.0) + sum;  // π/2 + сумма ряда

        // Вывод строки таблицы
        printf("| %8.3f | %13.6f | %14.6f | %8d |\n", x, series_value, exact, count);
    }

    printf("------------------------------------------------------------\n");

    return 0;
}