#include <iostream>
#include <vector>


std::string Permutations(std::string& word, std::vector<int>& code) {
    std::string result(word.size(), ' ');
    for (int i = 0; i < code.size(); i++) {
        result[code[i] - 1] = word[i];
    }
    return result;
}


int main() {
    int n, k;
    std::cout << "Введите числа n и k: ";
    std::cin >> n >> k;
    std::vector<int> code(n);
    std::cout << "Введите перестановку: ";
    while (true) {
        bool input = true;
        for (int i = 0; i < n; i++) {
            std::cin >> code[i];
            if (code[i] < 1 || code[i] > n) {
                input = false;
                break;
            }
        }
        if (input) {
            break;
        }
        std::cout << "Ошибка, все числа должны быть от 1 до " << n << ". Введите перестановку заново: ";
    }
    std::cout << "Введите слово: ";
    std::string word; // зашифрованное слово
    std::cin >> word;

    while (k > 0) {
        word = Permutations(word, code);
        k--;
    }
    std::cout << "Зашифрованное слово: " << word;
}