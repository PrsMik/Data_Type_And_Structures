#include <iostream>
#include <vector>
#include <algorithm>

bool check(unsigned long long moduleWidth, unsigned long long moduleHeight,
    unsigned long long width, unsigned long long height, long long x, long long n) {
    unsigned long long moduleModifWidth = moduleWidth + 2 * x;
    unsigned long long moduleModifHeight = moduleHeight + 2 * x;
    unsigned long long maxPlacement = std::max(((width / moduleModifWidth) * (height / moduleModifHeight)),
        ((width / moduleModifHeight) * (height / moduleModifWidth)));
    return maxPlacement >= n;
}

int main() {
    unsigned long long modulesAmount, moduleWidth, moduleHeight, fieldWidth, fieldHeight;
    std::cin >> modulesAmount >> moduleWidth >> moduleHeight >> fieldWidth >> fieldHeight;

    unsigned long long left = 0;
    unsigned long long right = 1;

    while (check(moduleWidth, moduleHeight, fieldWidth, fieldHeight, right, modulesAmount)) {
        right *= 2;
    }

    while (right - left > 1) {
        unsigned long long mid = (right + left) / 2;
        if (check(moduleWidth, moduleHeight, fieldWidth, fieldHeight, mid, modulesAmount)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    std::cout << left;
}