#include <stdio.h>
#include <locale.h>

// Функция для подсчета уникальных элементов
int MLBB(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        int unique = 1; // предполагаем, что элемент уникален
        // Проверяем, был ли такой элемент раньше
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                unique = 0; // нашли дубликат 
            }
        }

        if (unique == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int arr[] = { 1,5,4,3,6,1,1,2,2,8,9,9,9,9,9,9};
    int z = sizeof(arr) / sizeof(arr[0]);
    printf("Массив: ");
    for (int i = 0; i < z; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int beb = MLBB(arr, z);
    printf("Уникальных элементов: %d\n", beb);

    return 0;
}