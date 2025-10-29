#include <stdio.h>
#include <malloc.h>
#include <locale.h>
float henkali(float* arr, int n) {
    int lastPositiveIndex = -1;

    // Находим индекс последнего положительного элемента
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            lastPositiveIndex = i;
        }
    }

    // Если положительных элементов нет или он первый
    if (lastPositiveIndex <= 0) {
        return 0;
    }

    // Считаем сумму до последнего положительного
    float sum = 0;
    for (int i = 0; i < lastPositiveIndex; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    printf("Введите количество элементов: ");
    scanf_s("%d", &n);

    float* arr = (float*)malloc(n * sizeof(float));

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &arr[i]);
    }

    float result = henkali(arr, n);
    printf("Сумма элементов до последнего положительного: %.2f\n", result);

    free(arr);
    return 0;
}