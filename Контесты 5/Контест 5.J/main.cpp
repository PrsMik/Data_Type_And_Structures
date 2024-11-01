#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
	std::map<int, int> tree;

	while (true) {
		int x;
		std::cin >> x;
		if (x == 0) {
			break;
		}
		++tree[x];
	}

	for (auto iter = tree.begin(); iter != tree.end(); ++iter) {
		std::cout << iter->first << " " << iter->second << "\n";
	}
}