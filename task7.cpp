#include <iostream>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;
    if (s.length() != 6) {
        std::cout << "No" << std::endl;
        return 0;
    }
    if (!isupper(s[0])) {
        std::cout << "No" << std::endl;
        return 0;
    }
    for (int i = 1; i <= 3; i++) {
        if (!isdigit(s[i])) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    for (int i = 4; i <= 5; i++) {
        if (!isupper(s[i])) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}