#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int pelmeni(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if ((arr[i] ^ arr[i - 1]) < 0) { // Проверка изменения знака через XOR
            return i;
        }
    }
    return -1; // Если изменения знака нет
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    printf("Введите количество элементов: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    int pos = pelmeni(arr, n);
    if (pos != -1) {
        printf("Первое изменение знака найдено и оно на позиции: %d\n", pos);
    }
    else {
        printf("Изменение знака не найдено\n");
    }

    free(arr);
    return 0;
}