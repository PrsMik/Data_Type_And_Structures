#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long TreesByWorker(unsigned long long days, unsigned long long efficiency, unsigned long long daysToRest) {
    unsigned long long daysOfWork = days - days / daysToRest;
    return daysOfWork * efficiency;
}

bool check(unsigned long long time, unsigned long long firstEfficiency, unsigned long long firstDaysToRest,
    unsigned long long secondEfficiency, unsigned long long secondDaysToRest, unsigned long long trees) {
    unsigned long long res = 0;
    res += TreesByWorker(time, firstEfficiency, firstDaysToRest) +
        TreesByWorker(time, secondEfficiency, secondDaysToRest);
    return res >= trees;
}

int main() {
    unsigned long long trees, firstDaysToRest, secondDaysToRest, firstEfficiency, secondEfficiency;
    std::cin >> firstEfficiency >> firstDaysToRest >> secondEfficiency >> secondDaysToRest >> trees;

    unsigned long long left = 0;
    unsigned long long right = 1;

    while (!check(right, firstEfficiency, firstDaysToRest, secondEfficiency, secondDaysToRest, trees)) {
        right *= 2;
    }

    while (right - left > 1) {
        unsigned long long mid = (right + left) / 2;
        if (check(mid, firstEfficiency, firstDaysToRest, secondEfficiency, secondDaysToRest, trees)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    std::cout << right;
}