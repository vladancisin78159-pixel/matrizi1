#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    printf("n = ");
    scanf_s("%d", &n);

    int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                printf("NO\n");
                return 0; // Завершаем программу сразу
            }
        }
        free(A[i]);
    }
    free(A);

    printf("YES\n");
    return 0;
}