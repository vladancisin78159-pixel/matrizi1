#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

int probelitd(unsigned char c) {
    return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int main() {
    setlocale(LC_ALL, "Rus");
    FILE* input = fopen("zxc.txt", "w");
    if (input != NULL) {
        fprintf(input, "   Lllll,   \n");
        fprintf(input, "  Pedro,       \n");
        fprintf(input, " BrawlStars s s\n");
        fclose(input);
        printf("Создан файл zxc.txt\n");
    }

    input = fopen("zxc.txt", "r");
    FILE* output = fopen("bbb.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Ошибка открытия файлов\n");
        return 1;
    }

    char ch;
    int need_space = 0;

    while ((ch = fgetc(input)) != EOF) {
        if (probelitd(ch)) {
            need_space = 1;
        }
        else {
            if (need_space) {
                fputc(' ', output);
                need_space = 0;
            }
            fputc(ch, output);
        }
    }
    fclose(input);
    fclose(output);
    printf("Лексемы записаны в bbb.txt\n");

    return 0;
}