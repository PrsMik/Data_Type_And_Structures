#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

int main() {
	int n;
	std::cin >> n;

	std::multiset<int> arr;

	for (int i = 0; i != n; ++i) {
		int x;
		std::cin >> x;
		arr.insert(x);
	}

	double cost = 0;

	while (arr.size() != 1) {
		double sum = 0;
		sum += *arr.begin();
		arr.erase(arr.begin());
		sum += *arr.begin();
		arr.erase(arr.begin());
		cost += sum;
		arr.insert(sum);
	}

	std::cout << std::fixed << std::setprecision(2) << cost * 0.05;
}