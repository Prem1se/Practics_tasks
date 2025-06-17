#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<long long> snow(n + 1, 0);

    while (k--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int i, x;
            std::cin >> i >> x;
            snow[i] += x;
        } else if (type == 2) {
            int u, r;
            std::cin >> u >> r;
            long long sum = 0;
            for (int i = u; i <= r; i++) {
                sum += snow[i];
            }
            std::cout << sum << '\n';
        }
    }

    return 0;
}