#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main() {
    long double c;
    std::cin >> c;

    long double r = std::pow(c, 0.5);
    long double l = 0;
    long double eps = 1e-6;

    while (r - l > eps) {
        long double m = (r + l) / 2;
        if (std::pow(m, 2) + std::pow(m, 0.5) < c) {
            l = m;
        }
        else {
            r = m;
        }
    }

    std::cout << std::fixed << std::setprecision(6) << (r + l) / 2;
}