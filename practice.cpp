#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
        //Невероятное практическое задание с невероятными обьяснениями
//невероятная функция создания квадратной матрицы размером n x n *-* //
double** create_matrix(int n) {
    double** m = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        m[i] = (double*)malloc(n * sizeof(double));
    }
    return m;
}
//невероятно освобождаем память, занятой матрицей//
void free_matrix(double** m, int n) {
    for (int i = 0; i < n; i++) free(m[i]);
    free(m);
}

//Ввод матрицы
double** input_matrix(int n) {
    double** m = create_matrix(n);
    printf("Введите матрицу %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) { //заполн.строки
        printf("Строка %d: ", i + 1);
        for (int j = 0; j < n; j++) { //заполн.столбцы
            scanf_s("%lf", &m[i][j]);
        }
    }
    return m;
}
//Ввод вектора матрицы (свободных членов)-одномерный массив
double* input_vector(int n) {
    double* v = (double*)malloc(n * sizeof(double));
    printf("Введите вектор из %d элементов:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Элемент %d: ", i + 1);
        scanf_s("%lf", &v[i]); // Ввод значения и сохранение в соответствующем элементе вектора
    }
    return v; // Возвращаем заполненный вектор
}

// Невероятная функция вычисления определителя матрицы
double det(double** m, int n) {
    if (n == 1) return m[0][0]; // формула det для матрицы 1x1
    if (n == 2) return m[0][0] * m[1][1] - m[0][1] * m[1][0]; // формула det для матрицы 2x2

    double d = 0; // Инициализация определителя
    for (int k = 0; k < n; k++) { // Разложение по первой строке
        double** sub = create_matrix(n - 1); // Создаем  минор без первой строки и k-го столбца
        for (int i = 1; i < n; i++) {  // Заполняем подматрицу элементами исходной матрицы
            int col = 0; // Счетчик столбцов в минорчике
            for (int j = 0; j < n; j++) {
                if (j == k) continue; // Пропускаем k-й столбец
                sub[i - 1][col++] = m[i][j]; // Копируем элемент в минорчик
            }
        }
        // Определяем знак для алгебраического дополнения
        // Правило знаков: (-1)^(i+j), где i = номер строки, j = номер столбца
        double sign;
        if (k % 2 == 0) {
            sign = 1;
        }
        else {
            sign = -1;
        }

        d = d + (sign * m[0][k] * det(sub, n - 1));
        free_matrix(sub, n - 1);
    }
    return d;
}
// Невероятная функция вычисления обратной матрицы
double** inverse(double** m, int n) {
    double d = det(m, n); // Вычисляем определитель исходной матрицы

    // Проверяем, что определитель в диапазоне [-0.0000001, 0.0000001] всякое бывает
    if (d > -0.0000001 && d < 0.0000001) {
        printf("Обратную матрицу найти невозможно\n");
        return NULL;
    }

    double** inv = create_matrix(n); // Создаем матрицу для хранения обратной матрицы
    // Вычисляем обратную матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double** sub = create_matrix(n - 1); // Создаем минор без i-й строки и j-го столбца
            int rows = 0;
            for (int x = 0; x < n; x++) { // Проходим по всем строкам исходной матрицы
                if (x == i) continue;  // Пропускаем i-ю строку
                int col = 0; // Счетчик столбцов в миноре
                for (int y = 0; y < n; y++) {
                    if (y == j) continue;
                    sub[rows][col++] = m[x][y]; // Копируем элемент в минор
                }
                rows++;
            }
            // Вычисляем алгебраическое дополнение A(i,j)
            double sign1;
            if ((i + j) % 2 == 0) {
                sign1 = 1;
            }
            else {
                sign1 = -1;
            }
            // Записываем в транспонированную позицию (j,i) - это уже присоединенная матрица
            // Формула для каждого элемента inv[j][i] = (1/det) * (-1)^(i+j) * det(M(i,j))
            inv[j][i] = sign1 * det(sub, n - 1) / d;
            free_matrix(sub, n - 1);
        }
    }
    return inv;
}
// Невероятная функция решения системы линейных уравнений методом Крамера
double* Cramer(double** A, double* B, int n) { // тут A - матрица коэфф, B - матрица свобоных членов
    double d = det(A, n);   // Вычисляем главный определитель системы
    if (d == 0.0) {         //Проверяем на единственность, определитель не должен быть равен 0
        printf("Система не имеет единственного решения\n");
        return NULL;
    }
    // Выделяем память для вектора решений(наши иксы невероятные)
    double* X = (double*)malloc(n * sizeof(double));

    // Вычисляем каждую неизвестную по методу Крамера(x=detx\detA)
    for (int i = 0; i < n; i++) { // i - индекс заменяемого столбца
        double** A1 = create_matrix(n); //Создаем матрицу для вычисления определителей
        for (int r = 0; r < n; r++) { // Копируем исходную матрицу A в A1
            for (int c = 0; c < n; c++) {
                A1[r][c] = A[r][c];
            }
            A1[r][i] = B[r];  // Заменяем i-й столбец на вектор свободных членов B
        }
        X[i] = det(A1, n) / d;
        free_matrix(A1, n);
    }
    return X;
}

// Невероятная функция вывода матрицы

void print_matrix_result(double** m, int n, const char* name) {  // m-указатель на матрицу,n-размер матрицы
    printf("\n%s:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.4f ", m[i][j]);
        }
        printf("\n");
    }
}
// Невероятная функция вывода вектора решений
void print_vector_result(double* v, int n, const char* name) {  //v-указатель на вектор, n-размер вектора
    printf("\n%s:\n", name);
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, v[i]);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;

    printf("Размер матрицы: ");
    scanf_s("%d", &n);

    // Ввод значений в матрице
    double** A = input_matrix(n);
    double* B = input_vector(n);

    // Вывод обратной матрицы
    double** inv = inverse(A, n);
    if (inv) {
        print_matrix_result(inv, n, "Обратная матрица:");
        free_matrix(inv, n);
    }

    // Вывод решения методом Кррррамера
    double* X = Cramer(A, B, n);
    if (X) {
        print_vector_result(X, n, "Решение системы");
        free(X);
    }

    // Освобождение памяти
    free_matrix(A, n);
    free(B);

    return 0;

}
