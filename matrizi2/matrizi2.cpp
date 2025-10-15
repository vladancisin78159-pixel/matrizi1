
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 5

int main() {
    int matrix[N][M];

    // Инициализация генератора случайных чисел
    srand((unsigned)time(NULL));

    // Заполнение матрицы случайными числами
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 100; // числа от 0 до 99
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    // Поиск максимального элемента
    int max_value = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
            }
        }
    }
    // Вывод результата
    printf("\nМаксимальный элемент: %d\n", max_value);
    return 0;
}
