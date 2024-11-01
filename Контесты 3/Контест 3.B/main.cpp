#include <iostream>
#include <vector>

int LeftBinarySearch(std::vector<int>& arr, int x) {
    int l = -1;
    int r = arr.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (arr[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;
}

int RightBinarySearch(std::vector<int>& arr, int x) {
    int l = -1;
    int r = arr.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (arr[m] < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if (r == arr.size()) {
        return -1;
    }
    return r;
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
        int ind1 = LeftBinarySearch(firstArr, num);
        int ind2 = RightBinarySearch(firstArr, num);
        if (ind1 == -1) {
            std::cout << firstArr[ind2] << "\n";
        }
        else if (ind2 == -1) {
            std::cout << firstArr[ind1] << "\n";
        }
        else {
            if (num - firstArr[ind1] == firstArr[ind2] - num) {
                std::cout << firstArr[ind1] << "\n";
            }
            else if (num - firstArr[ind1] < firstArr[ind2] - num) {
                std::cout << firstArr[ind1] << "\n";
            }
            else {
                std::cout << firstArr[ind2] << "\n";
            }
        }
    }
}