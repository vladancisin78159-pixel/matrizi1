#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 3  // размер квадратной матрицы

// Функция для транспонирования матрицы
void trasponirovanie(int original[N][N], int transposed[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            transposed[i][j] = original[j][i];
        }
    }
}

// Функция для вывода матрицы
void vivod(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int original[N][N];
    int transposed[N][N];

    // Инициализация генератора случайных чисел
    srand((unsigned)time(NULL));

    // Заполнение исходной матрицы случайными числами
    printf("Исходная матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            original[i][j] = rand() % 100; // числа от 1 до 10
            printf("%3d", original[i][j]);
        }
        printf("\n");
    }

    // Транспонирование матрицы
    trasponirovanie(original, transposed);

    // Вывод результата
    printf("\nТранспонированная матрица:\n");
    vivod(transposed);

    return 0;
}