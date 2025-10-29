#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    printf("Введите n: ");
    scanf_s("%d", &n);

    int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
    }

    // Заполнение массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                A[i][j] = 1; // Диагональ
            }
            else if (i + j < n - 1) {
                A[i][j] = 0; // Выше диагонали
            }
            else {
                A[i][j] = 2; // Ниже диагонали
            }
        }
    }

    // Вывод массива
    printf("Массив:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}