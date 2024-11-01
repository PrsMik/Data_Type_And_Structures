#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

int main() {
	int n;
	std::cin >> n;
	std::set<int> tree;

	std::string prevCmd = "";
	std::string currCmd = "";
	
	int y = 0;
	int i = 0;

	for (int j = 0; j != n; ++j) {
		std::cin >> currCmd;
		if (currCmd == "+") {
			std::cin >> i;
			if (prevCmd == "?") {
				tree.insert((i + y) % static_cast<int>(std::pow(10, 9)));
			}
			else {
				tree.insert(i);
			}
			prevCmd = "+";
		}
		else if (currCmd == "?") {
			std::cin >> i;
			auto it = tree.lower_bound(i);
			if (it != tree.end()) {
				y = *it;
			}
			else {
				y = -1;
			}
			std::cout << y << "\n";
			prevCmd = "?";
		}
	}

}