#include <iostream>
#include <vector>

void CountSwaps(std::vector<int> A) {
    int count = 0;
    for (size_t i = 0; i + 1 != A.size(); ++i) {
        bool swapped = false;
        for (size_t j = 0; j + 1 + i != A.size(); ++j) {
            if (A.at(j) > A.at(j + 1)) {
                std::swap(A.at(j), A.at(j + 1));
                ++count;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    std::cout << count;
}

int main() {
    int size;
    int x;
    std::vector<int> numbers;
    std::cin >> size;
    for (int i = 0; i != size; ++i) {
        std::cin >> x;
        numbers.push_back(x);
    }
    CountSwaps(numbers);
}