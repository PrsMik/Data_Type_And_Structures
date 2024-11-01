#include <iostream>
#include <vector>
#include <algorithm>

void CountSort(std::vector<int>& A) {
    int maxElem = *std::max_element(A.begin(), A.end());
    std::vector<int> count(maxElem + 1);

    for (int x : A) {
        count[x] += 1;
    }

    A.clear();

    for (int i = 0; i != maxElem + 1; ++i) {
        for (int j = 0; j != count[i]; j++) {
            A.push_back(i);
        }
    }
}

int main() {
    int x;
    std::vector<int> numbers;

    while (std::cin >> x) {
        numbers.push_back(x);
    }

    CountSort(numbers);

    for (size_t i = 0; i != numbers.size(); ++i) {
        if (i + 1 != numbers.size()) {
            std::cout << numbers[i] << " ";
        }
        else {
            std::cout << numbers[i];
        }
    }
}