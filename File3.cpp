#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");

    FILE* file = fopen("pivasik.txt", "w");
    if (file != NULL) {
        fprintf(file, "Banan\n");
        fprintf(file, "MeganFox\n");
        fprintf(file, "ded\n");
        fclose(file);
        printf("Создан файл pivasik.txt с 3 строками\n");
    }

    file = fopen("pivasik.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    char line[1000];
    int count = 0;    

    while (fgets(line, sizeof(line), file) != NULL) {
        // УДАЛЕНИЕ СИМВОЛОВ НОВОЙ СТРОКИ!!!!!!!!!!!!!! запомнить понять и тд\n)
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n')) {
            line[len - 1] = '\0';
            len = len - 1;
        }

        // проверка на что первый и последняя строка одинаковые UwU
        if (len > 0 && line[0] == line[len - 1]) {
            count++;
            printf("Найдена строка: %s\n", line);
        }
    }

    fclose(file);
    printf("Количество строк: %d\n", count);

    return 0;
}