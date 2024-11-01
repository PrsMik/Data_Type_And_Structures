#include <iostream>
#include <vector>
#include <algorithm>

bool check(std::vector<int>& ropes, int x, int k) {
    int c = 0;
    for (int rope : ropes) {
        c = c + rope / x;
    }
    return c >= k;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ropes;

    for (int i = 0; i != n; ++i) {
        int x;
        std::cin >> x;
        ropes.push_back(x);
    }

    int left = 0;
    int right = 1e7 + 1;

    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(ropes, mid, k)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    std::cout << left;
}