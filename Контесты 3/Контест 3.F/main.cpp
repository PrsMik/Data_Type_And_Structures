#include <iostream>
#include <vector>
#include <algorithm>

bool check(int time, int x, int y, int n) {
    return time / x + time / y < n - 1;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    int left = 0;
    int right = (n - 1) * std::max(x, y);

    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(mid, x, y, n)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    std::cout << right + std::min(x, y);
}