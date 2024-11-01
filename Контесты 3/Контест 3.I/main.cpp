#include <iostream>
#include <vector>
#include <map>

int main() {
	int n;

	std::cin >> n;

	std::map<int, int> firstArr;

	for (int i = 0; i != n; ++i) {
		int x;
		std::cin >> x;
		++firstArr[x];
	}

	int m;

	std::cin >> m;

	std::vector<int> secondArr;

	for (int i = 0; i != m; ++i) {
		int x;
		std::cin >> x;
		secondArr.push_back(x);
	}

	for (int item : secondArr) {
		std::cout << firstArr[item] << " ";
	}
}