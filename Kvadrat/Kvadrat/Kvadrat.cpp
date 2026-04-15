#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int MinIndexxx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[MinIndexxx]) {
                MinIndexxx = j;
            }
        }
        if (MinIndexxx != i) {
            swap(arr[i], arr[MinIndexxx]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<int> ww = { 5, 2, 8, 3, 9, 1 };
    selectionSort(ww);

    cout << "Отсортировано выбором: ";
    for (int x : ww) cout << x << " ";
    cout << endl;
    return 0;
}