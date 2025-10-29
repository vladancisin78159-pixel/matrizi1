#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Rus");
    int Z, M;
    printf("Введите N и M: ");
    scanf_s("%d %d", &Z, &M);

    int** A = (int**)malloc(Z * sizeof(int*));
    for (int i = 0; i < Z; i++) {
        A[i] = (int*)malloc(M * sizeof(int));
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < M; j++) {
            scanf_s("%d", &A[i][j]);
        }
    }

    // Среднее арифметическое главной диагонали
    int count = 0;
    double sum = 0;
    for (int i = 0; i < Z && i < M; i++) {
        sum += A[i][i];
        count++;
    }
    double srednee = sum / count;

    // Произведение побочной диагонали
    double x = 1;
    count = 0;
    for (int i = 0; i < Z && (M - 1 - i) >= 0; i++) {
        x *= A[i][M - 1 - i];
        count++;
    }
    if (count == 0) {
        x = 0;
    }

    // Разница
    double raznica = srednee - x;

    printf("Среднее арифметическое главной диагонали: %.2f\n", srednee);
    printf("Произведение побочной диагонали: %.2f\n", x);
    printf("Разница: %.2f\n", raznica);

    // Освобождение памяти
    for (int i = 0; i < Z; i++) {
        free(A[i]);
    }
    free(A);

    return 0;

}
