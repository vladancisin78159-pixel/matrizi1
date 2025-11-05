#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    FILE* file1 = fopen("Dota1.txt", "w");
    if (file1 != NULL) {
        fputs("Перфоратор \n", file1);
        fclose(file1);
    }

    FILE* file2 = fopen("Dota2.txt", "w");
    if (file2 != NULL) {
        fputs("МегаПерфоратор\n", file2);
        fclose(file2);
    }

    FILE* file3 = fopen("Dota3.txt", "w");
    if (file3 != NULL) {
        fputs("УльтраМегаПерфоратор\n", file3);
        fclose(file3);
    }
    printf("Созданы 3 файла\n");

    long sizes[3];
    const char* filenames[] = { "Dota1.txt", "Dota2.txt", "Dota3.txt" };

    for (int i = 0; i < 3; i++) {
        FILE* files = fopen(filenames[i], "r");
        if (files != NULL) {
            int size = 0;
            int ch;
            while ((ch = fgetc(files)) != EOF) {
                size++;
            }
            sizes[i] = size;
            fclose(files);
        }
    }

    // ПОИСК САМОГО ДЛИННОГО И САМОГО КОРОТКОГО ФАЙЛА
    int max_index = 0;
    int min_index = 0;
    for (int i = 1; i < 3; i++) {
        if (sizes[i] > sizes[max_index]) max_index = i;
        if (sizes[i] < sizes[min_index]) min_index = i;
    }

    printf("Самый длинный файл: %s\n", filenames[max_index]);
    printf("Самый короткий файл: %s\n", filenames[min_index]);

    // ОБМЕН СОДЕРЖИМЫМ МЕЖДУ САМЫМ ДЛИННЫМ И САМЫМ КОРОТКИМ ФАЙЛОМ
    // Шаг 1: Сохраняем содержимое самого длинного файла во временный файл
    FILE* longest_file = fopen(filenames[max_index], "r");
    FILE* copia = fopen("temp.txt", "w");

    if (longest_file != NULL && copia != NULL) {
        int ch;
        while ((ch = fgetc(longest_file)) != EOF) {
            fputc(ch, copia);
        }
        fclose(longest_file);
        fclose(copia);
    }

    //содержимое самого короткого файла в самый длинный
    FILE* shortest_file = fopen(filenames[min_index], "r");
    longest_file = fopen(filenames[max_index], "w");

    if (shortest_file != NULL && longest_file != NULL) {
        int ch;
        while ((ch = fgetc(shortest_file)) != EOF) {
            fputc(ch, longest_file);
        }
        fclose(shortest_file);
        fclose(longest_file);
    }

    //Копируем сохраненное содержимое в самый короткий файл
    copia = fopen("temp.txt", "r");
    shortest_file = fopen(filenames[min_index], "w");

    if (copia != NULL && shortest_file != NULL) {
        int ch;
        while ((ch = fgetc(copia)) != EOF) {
            fputc(ch, shortest_file);
        }
        fclose(copia);
        fclose(shortest_file);

        printf("Файлы свапнуты!\n");
    }
    return 0;
}