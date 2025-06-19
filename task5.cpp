#include <iostream>

int main() {
    int w, h;
    std::cin >> h >> w;
    int** matrix = new int*[h];
    for (int i = 0; i < h; i++) {
        matrix[i] = new int[w];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> matrix[i][j];
        }
    }
    int x_left_up = -1;
    int y_left_up = -1;
    bool found = false;
    for (int i = 0; i < h && found == false; i++) {
        for (int j = 0; j < w && found == false; j++) {
            if (matrix[i][j] == 1) {
                x_left_up = j;
                y_left_up = i;
                found = true;
            }
        }
    }
    x_left_up--;
    y_left_up--;

    int x_right_bottom = -1;
    int y_right_bottom = -1;
    bool found2 = false;
    for (int i = h - 1; i >= 0 && found2 == false; i--) {
        for (int j = w - 1; j >= 0 && found2 == false; j--) {
            if (matrix[i][j] == 1) {
                x_right_bottom = j;
                y_right_bottom = i;
                found2 = true;
            }
        }
    }
    x_right_bottom++;
    y_right_bottom++;
    std::cout << y_left_up << " " << x_left_up << " " << y_right_bottom << " " << x_right_bottom;

    for (int i = 0; i < h; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}