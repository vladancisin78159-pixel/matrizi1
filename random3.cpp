#include <stdio.h>

#define SIZE 5

int main() {
    int matrix[SIZE][SIZE];
    int value = 1;

    int verxstroka = 0, nizstroka = SIZE - 1;
    int left = 0, right = SIZE - 1;

    // Заполнение матрицы по спирали
    while (verxstroka <= nizstroka && left <= right) {
        // Верхняя строка: слева направо
        for (int i = left; i <= right; i++) {
            matrix[verxstroka][i] = value++;
        }
        verxstroka++;

        // Правый столбец: сверху вниз
        for (int i = verxstroka; i <= nizstroka; i++) {
            matrix[i][right] = value++;
        }
        right--;

        // Нижняя строка: справа налево
        if (verxstroka <= nizstroka) {
            for (int i = right; i >= left; i--) {
                matrix[nizstroka][i] = value++;
            }
            nizstroka--;
        }

        // Левый столбец: снизу вверх
        if (left <= right) {
            for (int i = nizstroka; i >= verxstroka; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }

    // Вывод матрицы, заполненной по спирали
    printf("Результат:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}