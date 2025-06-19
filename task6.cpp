#include <iostream>
#include <vector>

int MaxPairs(int a, int b, int x, int y) {
    int B_pairs = std::min(b, x);
    int remain = (x - B_pairs) + y;
    int A_pairs = std::min(a, remain);
    return B_pairs + A_pairs;

}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;
        result.push_back(MaxPairs(a, b, x, y));
    }
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
}