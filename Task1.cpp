#include <iostream>
#include <algorithm>
#include <random>

void BuildPyramid(int** Pyramid, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 99);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            Pyramid[i][j] = distrib(gen);
            std::cout << Pyramid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void findMinPath(int** pyramid, int size) {
    int** dp = new int*[size];
    for (int i = 0; i < size; i++) {
        dp[i] = new int[size];
    }

    for (int j = 0; j < size; j++) {
        dp[size-1][j] = pyramid[size-1][j];
    }

    for (int i = size-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int min_val = dp[i+1][j];
            if (j + 1 <= i + 1) {
                min_val = std::min(min_val, dp[i+1][j+1]);
            }
            dp[i][j] = pyramid[i][j] + min_val;
        }
    }

    std::cout << "Минимальная сумма: " << dp[0][0] << std::endl;
    std::cout << "Оптимальный маршрут: " << pyramid[0][0];

    int col = 0;
    for (int i = 1; i < size; i++) {
        int min_val = dp[i][col];
        int new_col = col;
        if (col+1 <= i && dp[i][col+1] < min_val) {
            min_val = dp[i][col+1];
            new_col = col+1;
        }
        col = new_col;
        std::cout << " " << pyramid[i][col];
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        delete[] dp[i];
    }
    delete[] dp;
}

int main() {
    int size = 0;
    std::cout << "Введите высоту пирамиды: ";
    std::cin >> size;
    if (size <= 0) {
        std::cout << "Неверная высота" << std::endl;
    }

    int** pyramid = new int*[size];
    for (int i = 0; i < size; i++) {
        pyramid[i] = new int[i+1];
    }

    BuildPyramid(pyramid, size);
    findMinPath(pyramid, size);

    for (int i = 0; i < size; i++) {
        delete[] pyramid[i];
    }
    delete[] pyramid;

    return 0;
}