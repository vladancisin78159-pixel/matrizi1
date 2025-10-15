#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 3  // размер квадратной матрицы

int main() {
    setlocale(LC_ALL, "Rus");
    int matrix[N][N];

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение матрицы случайными числами
    printf("Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10 + 1; // числа от 1 до 10
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    // Поиск строки с максимальной суммой
    int max_summa = 0;
    int max_index = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }

        if (i == 0 || sum > max_summa) {
            max_summa = sum;
            max_index = i;
        }
    }

    // Поиск столбца с минимальной суммой
    int min_summa = 0;
    int min_index = 0;

    for (int j = 0; j < N; j++) {
        int summ = 0;
        for (int i = 0; i < N; i++) {
            summ += matrix[i][j];
        }

        if (j == 0 || summ < min_summa) {
            min_summa = summ;
            min_index = j;
        }
    }

    // Вывод результатов
    printf("\nСтрока с максимальной суммой: %d (%d)\n",
        max_index + 1, max_summa);
    printf("Столбец с минимальной суммой: %d (сумма = %d)\n",
        min_index + 1, min_summa);

    return 0;
}