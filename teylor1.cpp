#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функция для вычисления e^(-x) с помощью ряда Тейлора с заданной точностью
double exp_series(double x, double eps) {
    double sum = 1.0;    // первый член ряда (n=0)
    double term = 1.0;   // текущий член ряда
    int n = 1;           // номер текущего члена

    // Вычисляем члены ряда пока их модуль больше точности
    while (fabs(term) >= eps) {
        // Вычисляем следующий член через предыдущий: term_n = term_(n-1) * (-x) / n
        term *= (-x) / n;
        sum += term;
        n++;
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    double x_start, x_end, dx, epsilon;

    // Ввод параметров
    printf("Введите начальное значение x: ");
    scanf_s("%lf", &x_start);
    printf("Введите конечное значение x: ");
    scanf_s("%lf", &x_end);
    printf("Введите шаг dx: ");
    scanf_s("%lf", &dx);
    printf("Введите точность eps: ");
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

    // Вывод заголовка таблицы
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("|        x |   Ряд Тейлора | Точное значение |   Членов |\n");
    printf("------------------------------------------------------------\n");

    // Вычисление и вывод значений функции
    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double sum = 1.0;        // начальная сумма (n=0)
        double term = 1.0;       // текущий член ряда
        int n = 1;               // номер текущего члена
        int count = 1;           // счетчик членов (уже учтен n=0)

        // Вычисление суммы ряда до достижения точности
        while (fabs(term) >= epsilon) {
            // Рекуррентная формула: term_n = term_(n-1) * (-x) / n
            term *= (-x) / n;
            sum += term;
            n++;
            count++;
        }

        // Точное значение функции
        double exact = exp(-x);

        // Вывод строки таблицы
        printf("| %8.3f | %13.6f | %14.6f | %8d |\n", x, sum, exact, count);
    }

    printf("------------------------------------------------------------\n");

    return 0;
}