#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool Sorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i - 1] > arr[i]) return false;
    return true;
}

void bogosort(vector<int>& arr) {
    int iterations = 0;

    while (!Sorted(arr)) {
        iterations++;
        for (int i = 0; i < arr.size(); ++i) {
            int j = rand() % arr.size();
            swap(arr[i], arr[j]);
        }
    }

    cout << "Всего попыток: " << iterations << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    vector<int> ww = { 3, 1, 4, 2 };

    cout << "Исходный массив: ";
    for (int x : ww) cout << x << " ";
    cout << endl;

    bogosort(ww);

    cout << "Отсортировано: ";
    for (int x : ww) cout << x << " ";
    cout << endl;

    return 0;
}