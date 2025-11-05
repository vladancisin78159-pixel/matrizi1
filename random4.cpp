#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void pascal(int n) {

    int** shaurma = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        shaurma[i] = (int*)malloc((i + 1) * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        //  пробелы для красивого вывода(ну тип красиво будет)
        for (int space = 0; space < n - i - 1; space++) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                shaurma[i][j] = 1;
            }
            else {
                shaurma[i][j] = shaurma[i - 1][j - 1] + shaurma[i - 1][j];
            }
            printf("%d ", shaurma[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(shaurma[i]);
    }
    free(shaurma);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int stroki;
    printf("Введите количество строк треугольника Паскаля: ");
    scanf_s("%d", &stroki);

    pascal(stroki);

    return 0;
}