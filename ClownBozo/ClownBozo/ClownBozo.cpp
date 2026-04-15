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

void bozosort(vector<int>& arr) {
    int iterations = 0;

    while (!Sorted(arr)) {
        iterations++;
        int i = rand() % arr.size();
        int j = rand() % arr.size();
        swap(arr[i], arr[j]);
    }

    cout << "Всего попыток: " << iterations << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    vector<int> ww = { 3, 1, 5, 2, 4, 7};

    cout << "Исходный массив: ";
    for (int x : ww) cout << x << " ";
    cout << endl;

    bozosort(ww);

    cout << "Результатик сортировки: ";
    for (int x : ww) cout << x << " ";
    cout << endl;

    return 0;
}