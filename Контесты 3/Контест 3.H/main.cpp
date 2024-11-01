#include <iostream>
#include <vector>
#include <algorithm>

bool check(long long width, long long height, long long x, long long n) {
    return ((x / width) * (x / height)) >= n;
}

int main() {
    long long w, h, n;
    std::cin >> w >> h >> n;

    long long left = 0;
    long long right = 1;

    while (!check(w, h, right, n)) {
        right *= 2;
    }

    while (right - left > 1) {
        long long mid = (right + left) / 2;
        if (check(w, h, mid, n)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    std::cout << right;
}