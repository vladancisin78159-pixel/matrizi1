#include <iostream>
#include <vector>

using namespace std;

vector<int> stalinSort(const vector<int>& arr) {
    if (arr.empty()) 
        return {};

    vector<int> result;
    result.push_back(arr[0]);

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] >= result.back()) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<int> ww = { 5, 2, 8, 3, 9, 1, 4, 7 };
    vector<int> sorted = stalinSort(ww);

    cout << "Результатик сортировки: ";
    for (int x : sorted) cout << x << " ";
    cout << endl;
    return 0;
}