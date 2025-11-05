#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

int probelidt(unsigned char c) {
    return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int main() {
    setlocale(LC_ALL, "Rus");
    FILE* file = fopen("text_file.txt", "w");
    if (file != NULL) {
        fprintf(file, "S1mple\n");
        fprintf(file, "le le let me die\n");
        fprintf(file, "watch demo\n");
        fclose(file);
        printf("Создан файл text_file.txt\n");
    }

    file = fopen("text_file.txt", "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    char buffer[1024];
    size_t bytes;
    int  vsegosimvolov= 0;
    int lines = 0;
    int prabelovitd = 0;
    while ((bytes = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < bytes; i++) {
            vsegosimvolov++;

            if (probelidt(buffer[i])) {
                prabelovitd++;
            }

            if (buffer[i] == '\n') {
                lines++;
            }
        }
    }
    fclose(file);

    printf("Общее количество символов: %d\n", vsegosimvolov);
    printf("Количество строк: %d\n", lines);
    printf("Количество пробельных символов: %d\n", prabelovitd);

    float procent = prabelovitd * 100.0 / vsegosimvolov;
    printf("Процент пробельных символов: %f\n", procent);


    return 0;
}