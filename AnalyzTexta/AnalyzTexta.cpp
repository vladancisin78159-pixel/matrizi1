#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <windows.h>

using namespace std;

// Перевод в нижний регистр еу
string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        unsigned char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            s[i] = c + 32;
        }
        else if (c >= 192 && c <= 223) {
            s[i] = c + 32;
        }
    }
    return s;
}

// Удаляем знаки препинания еу
string cleanWord(string w) {
    string res = "";
    for (int i = 0; i < w.length(); i++) {
        unsigned char c = w[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= 192 && c <= 255) ||
            (c >= '0' && c <= '9') || c == '-') {
            res += c;
        }
    }
    return res;
}

// Разбиение строки на слова еу
vector<string> extractWords(string line) {
    vector<string> words; //слова
    string word = ""; //строка

    for (int i = 0; i < line.length(); i++) {
        unsigned char c = line[i];

        // Проверяем, является ли символ частью слова еу
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= 192 && c <= 255) || 
            (c >= '0' && c <= '9') || c == '-') {
            word += c;
        }
        else {
            if (word.length() > 0) {
                // Сначала очищаем от знаков препинания, потом переводим в нижний регистр еу
                string cleaned = cleanWord(word);
                if (cleaned.length() > 0) {
                    words.push_back(toLower(cleaned));
                }
                word = "";
            }
        }
    }

    if (word.length() > 0) {
        string cleaned = cleanWord(word);
        if (cleaned.length() > 0) {
            words.push_back(toLower(cleaned));
        }
    }

    return words;
}

// Подсчет сколько раз слово встречается еу
int countWord(vector<string>& all, string target) {
    int cnt = 0;
    for (int i = 0; i < all.size(); i++) {
        if (all[i] == target) cnt++;
    }
    return cnt;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string name;
    cout << "Введите имя файла: ";
    cin >> name;

    ifstream file(name);
    if (!file.is_open()) {
        cout << "Ошибка!" << endl;
        return 1;
    }

    vector<string> allWords;
    string line;

    cout << "Чтение файла..." << endl;

    while (getline(file, line)) {
        vector<string> w = extractWords(line);
        for (int i = 0; i < w.size(); i++) {
            allWords.push_back(w[i]); //добавляем все слова в общие еу
        }
    }

    file.close();

    cout << "Всего слов: " << allWords.size() << endl;

    // Уникальные слова еуууу
    vector<string> unique;
    for (int i = 0; i < allWords.size(); i++) {
        bool found = false; // флаг найдено ли слово еу
        for (int j = 0; j < unique.size(); j++) {
            if (unique[j] == allWords[i]) {
                found = true;
                break;
            }
        }
        if (!found) unique.push_back(allWords[i]);
    }

    cout << "Уникальных слов: " << unique.size() << endl;

    sort(unique.begin(), unique.end());

    string word;
    while (true) { //многократный поиск слов еу
        cout << "\nВведите слово (exit - выход): ";
        cin >> word;

        if (word == "exit") break;

        string low = toLower(word);

        // Бинарный поиск еу еу еу еу
        int L = 0, R = unique.size() - 1;
        bool ok = false;

        while (L <= R) {
            int M = (L + R) / 2;
            if (unique[M] == low) {
                ok = true;
                break;
            }
            else if (unique[M] < low) L = M + 1;
            else R = M - 1;
        }

        if (ok) {
            int cnt = countWord(allWords, low);
            cout << " Найдено Слово \"" << word << "\" встречается " << cnt << " раз(а)" << endl;
        }
        else {
            cout << "Не найдено" << endl;
        }
    }

    cout << "Программа завершена" << endl;
    return 0;
}
