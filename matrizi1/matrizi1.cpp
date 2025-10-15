#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define M 2

int main() {
    int A[N][M];
    int B[N][M];
    int C[N][M];

    // Инициализация генератора случайных чисел
    srand((unsigned)time(NULL));

    // Заполнение матриц случайными числами
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rand() % 100; // числа от 0 до 99
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            B[i][j] = rand() % 100;
        }
    }

    // Сложение матриц
    printf("\n C = A + B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}