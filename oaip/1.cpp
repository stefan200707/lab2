#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main() {
    const int SIZE = 10;
    char a[SIZE];
    cout << "Введите строку: ";
    cin.getline(a, SIZE);
    const char* delimiters = " \t\n";
    char* word = strtok(a, delimiters);
    if (word == nullptr) {
        cout << "Нет слов.\n";
        return 0;
    }
    int ka = 0;               
    int mindl = INT_MAX;      
    int c = 0;
    int ks = 0;
    while (word != nullptr) {
        int lastka = 0; 
        if (word[0] == 'a' || word[0] == 'A') ka++;
        int len = strlen(word);
        if (len < mindl) mindl = len;
        if (word[0] == word[strlen(word)-1]) ks++;
        for (char* p = word; *p != '\0'; p++) {
            *p = tolower(*p);
            if (*p == 'a') lastka++;
        }

        c = lastka;

        word = strtok(nullptr, delimiters); // получить следующее слово
    }

    cout << "Всего слов, начинающихся на 'a'/'A': " << ka << '\n';
    cout << "Минимальная длина слова: " << mindl << '\n';
    cout << "Количество а в последнем слове: " << c << '\n';
    cout << "Количество слов в которых первый и последний символ одинаковые: " << ks << '\n';
    return 0;
}
