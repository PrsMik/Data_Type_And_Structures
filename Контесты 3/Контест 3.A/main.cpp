#include <iostream>
#include <vector>
#include <stack>

bool BinarySearch(std::vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == x) {
            return true;
        }
        else if (arr[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;

    std::vector<int> firstArr;
    std::vector<int> secondArr;

    for (int i = 0; i != n; ++i) {
        int x;
        std::cin >> x;
        firstArr.push_back(x);
    }

    for (int i = 0; i != k; ++i) {
        int x;
        std::cin >> x;
        secondArr.push_back(x);
    }

    for (int num : secondArr) {
        if (BinarySearch(firstArr, num)) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
}