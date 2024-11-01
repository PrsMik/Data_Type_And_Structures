#include <iostream>
#include <vector>

void SelectionSort(std::vector<int> A) {
    for (size_t i = 0; i + 1 != A.size(); ++i) {
        int maxElem = A.at(i);
        size_t ind = i;
        for (size_t j = i + 1; j != A.size(); ++j) {
            if (A.at(j) > maxElem) {
                maxElem = A.at(j);
                ind = j;
            }
        }
        if (i != ind) {
            std::swap(A.at(ind), A.at(i));
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
    SelectionSort(numbers);
}