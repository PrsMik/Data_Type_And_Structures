#include <iostream>
#include <vector>

bool check(std::vector<int>& stalls, int distance, int neededCows) {
    int enteredCows = 1;
    int lastEnteredCow = stalls[0];
    for (int stall : stalls) {
        if (stall - lastEnteredCow >= distance) {
            ++enteredCows;
            lastEnteredCow = stall;
        }
    }
    return enteredCows >= neededCows;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> stalls;

    for (int ind = 0; ind != n; ++ind) {
        int x;
        std::cin >> x;
        stalls.push_back(x);
    }

    int left = 0;
    int right = stalls.back() - stalls[0] + 1;


    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(stalls, mid, k)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    std::cout << left;
}