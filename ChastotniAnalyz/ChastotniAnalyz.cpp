#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

// Перевод в нижний регистр (работает с русскими буквами)
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

// Разбиение строки на слова (работает с русскими буквами)
vector<string> extractWords(string line) {
    vector<string> words;
    string word = "";

    for (int i = 0; i < line.length(); i++) {
        unsigned char c = line[i];

        // Проверка на буквы и цифры
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= 192 && c <= 255) ||  // русские буквы 
            (c >= '0' && c <= '9')) {

            // Преобразуем заглавные в строчные
            if (c >= 'A' && c <= 'Z') {
                word += (c + 32);
            }
            else if (c >= 192 && c <= 223) {
                word += (c + 32);
            }
            else {
                word += c;
            }
        }
        else {
            if (word.length() > 0) {
                words.push_back(word);
                word = "";
            }
        }
    }

    if (word.length() > 0) {
        words.push_back(word);
    }

    return words;
}

int main() {
    // Настройка кодировки для русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string name;
    cout << "Введите имя файла: ";
    cin >> name;

    ifstream file(name);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла еу" << endl;
        return 1;
    }

    vector<string> allWords;
    string line;

    cout << "Чтение файла.." << endl;

    while (getline(file, line)) {
        vector<string> w = extractWords(line); //возращаем вектор слов
        for (int i = 0; i < w.size(); i++) {
            allWords.push_back(w[i]); //добавляем все слова в общие
        }
    }

    file.close();

    cout << "\nВсего слов: " << allWords.size() << endl;

    // Считаем частоту слов
    vector<pair<string, int>> chastota; // слово частота

    for (int i = 0; i < allWords.size(); i++) { //first-слово second-частота
        bool found = false;
        for (int j = 0; j < chastota.size(); j++) {
            if (chastota[j].first == allWords[i]) {
                chastota[j].second++;
                found = true;
                break;
            }
        }
        if (!found) {
            chastota.push_back(make_pair(allWords[i], 1));
        }
    }

    cout << "Уникальных слов: " << chastota.size() << endl;

    // Сортируем по частоте (от большего к меньшему)
    sort(chastota.begin(), chastota.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) { //функция для сравнения
            return a.second > b.second;
        });

    // 10 самых частых
    cout << "\n10 САМЫХ ЧАСТЫХ СЛОВ ===" << endl;
    for (int i = 0; i < 10 && i < chastota.size(); i++) {
        cout << i + 1 << ". " << chastota[i].first << " - " << chastota[i].second << " раз" << endl;
    }

    // 10 самых редких
    cout << "\n 10 САМЫХ РЕДКИХ СЛОВ" << endl;
    int rareCount = 0;
    for (int i = chastota.size() - 1; i >= 0 && rareCount < 10; i--) {
        if (chastota[i].second == 1) {  // показываем только слова, которые встречаются 1 раз
            cout << rareCount + 1 << ". " << chastota[i].first << " - 1 раз" << endl;
            rareCount++;
        }
    }
    // Поиск слова
    cout << "\n ПОИСК СЛОВА " << endl;

    string word;
    while (true) {
        cout << "\nВведите слово (exit - выход): ";
        cin >> word;

        if (word == "exit") break;

        word = toLower(word);

        bool found = false;
        for (int i = 0; i < chastota.size(); i++) {
            if (chastota[i].first == word) {
                cout << "Слово \"" << word << "\" встречается " << chastota[i].second << " раз(а)" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Слово \"" << word << "\" не найдено" << endl;
        }
    }

    cout << "\nПрограмма завершена" << endl;
    return 0;
}