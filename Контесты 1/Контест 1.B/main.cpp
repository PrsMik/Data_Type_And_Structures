#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> A) {
    for (size_t i = 1; i != A.size(); ++i) {
        size_t j = i;
        int elem = A.at(i);
        while (j > 0 && A.at(j - 1) > elem) {
            A.at(j) = A.at(j - 1);
            --j;
        }
        A.at(j) = elem;
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
    InsertionSort(numbers);
}