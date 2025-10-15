#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 3  // размер квадратной матрицы

int main() {
    setlocale(LC_ALL,"Rus");
    int matrix[N][N];

    // Инициализация генератора случайных чисел
    srand((unsigned)time(NULL));

    // Заполнение матрицы случайными числами
    printf("Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10 + 1; // числа от 1 до 10
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    // Сумма главной диагонали (i = j)
    int sum_main = 0;
    printf("\nГлавная диагональ: ");
    for (int i = 0; i < N; i++) {
        sum_main += matrix[i][i];
        printf("%d", matrix[i][i]);
        if (i < N - 1) printf(" + ");
    }
    printf(" = %d\n", sum_main);

    // Произведение побочной диагонали (i + j = N - 1)
    int product_secondary = 1;
    printf("Побочная диагональ: ");
    for (int i = 0; i < N; i++) {
        int j = N - 1 - i;  // вычисляем индекс столбца
        product_secondary *= matrix[i][j];
        printf("%d", matrix[i][j]);
        if (i < N - 1) printf(" * ");
    }
    printf(" = %d\n", product_secondary);

    return 0;
}