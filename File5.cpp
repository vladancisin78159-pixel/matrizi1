
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    printf("=== ЗАДАЧА 5 ===\n");

    // СОЗДАНИЕ 2 ФАЙЛОВ С РАЗНЫМ СОДЕРЖИМЫМ
    FILE* rx570 = fopen("rx570.txt", "w");
    FILE* rtx5090 = fopen("rtx5090.txt", "w");

    if (rx570 != NULL) {
        fprintf(rx570, "Overlord\n");
        fprintf(rx570, "можевельник\n");
        fclose(rx570);
    }

    if (rtx5090 != NULL) {
        fprintf(rtx5090, "ПоверБанк\n");
        fprintf(rtx5090, "Iphone\n");
        fprintf(rtx5090, "ПятьдесятДва\n");
        fclose(rtx5090);
    }
    printf("Созданы 2 файла для обмена\n");

    // ОБМЕН СОДЕРЖИМЫМ
    rx570 = fopen("rx570.txt", "r");
    FILE* temp = fopen("temp.txt", "w");

    if (rx570 != NULL && temp != NULL) {
        int ch;
        while ((ch = fgetc(rx570)) != EOF) {
            fputc(ch, temp);
        }
        fclose(rx570);
        fclose(temp);
    }

    // rtx5090 в rx570
    rtx5090 = fopen("rtx5090.txt", "r");
    rx570 = fopen("rx570.txt", "w");

    if (rtx5090 != NULL && rx570 != NULL) {
        int ch;
        while ((ch = fgetc(rtx5090)) != EOF) {
            fputc(ch, rx570);
        }
        fclose(rtx5090);
        fclose(rx570);
    }

    //временный файл в rtx5090
    temp = fopen("temp.txt", "r");
    rtx5090 = fopen("rtx5090.txt", "w");

    if (temp != NULL && rtx5090 != NULL) {
        int ch;
        while ((ch = fgetc(temp)) != EOF) {
            fputc(ch, rtx5090);
        }
        fclose(temp);
        fclose(rtx5090);

        printf("Свапнуто\n");
    }

    return 0;
}