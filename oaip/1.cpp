#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main() {
    const int SIZE = 100;
    const int MAX_WORDS = 10;
    char a[SIZE];
    char* words[MAX_WORDS];
    int word_count = 0;
    
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
    
    while (word != nullptr && word_count < MAX_WORDS) {
        words[word_count] = word; 
        
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

        word_count++;
        word = strtok(nullptr, delimiters);
    }
    cout << "Всего слов, начинающихся на 'a'/'A': " << ka << '\n';
    cout << "Минимальная длина слова: " << mindl << '\n';
    cout << "Количество а в последнем слове: " << c << '\n';
    cout << "Количество слов в которых первый и последний символ одинаковые: " << ks << '\n';
    for (int i = 0; i < word_count; i++) {
        for (int j = i + 1; j < word_count; j++) {
            for (int x = 0; x < strlen(words[i]); x++) {
                for (int y = 0; y < strlen(words[j]); y++) {
                    char t[SIZE];
                    strcpy(t,words[i]);
                    char p[SIZE];
                    strcpy(p,words[j]);
                    char c1 = t[x];
                    char c2 = p[y];
                    char* result1 = strchr(p,c1);
                    char* result2 = strchr(t,c2);
                    if (result1 != nullptr) {
                        cout << "Минимальная общая подстрока: " << c1 << " Между словами: " << p << " " << t << endl;
                        return 0;
                    }
                    if (result2 != nullptr) {
                        cout << "Минимальная общая подстрока: " << c2 << " Между словами " << t << " " << p <<endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    return 0;
}
