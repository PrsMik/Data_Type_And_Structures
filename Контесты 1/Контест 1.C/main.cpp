#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> A) {
    for (size_t i = 0; i + 1 != A.size(); ++i) {
        bool swapped = false;
        for (size_t j = 0; j + 1 + i != A.size(); ++j) {
            if (A.at(j) < A.at(j + 1)) {
                std::swap(A.at(j), A.at(j + 1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    for (const int number : A) {
        std::cout << number << " ";
    }
}

int main() {
    int x;
    std::vector<int> numbers;
    while (std::cin >> x) {
        numbers.push_back(x);
    }
    BubbleSort(numbers);
}