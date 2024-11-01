#include <iostream>
#include <queue>
#include <string>


int main() {
	std::priority_queue<int> heap;

	std::string command;

	while (std::cin >> command) {
		if (command == "CLEAR") {
			heap = std::priority_queue<int>();
		}
		else if (command == "ADD") {
			int x;
			std::cin >> x;
			heap.push(x);
		}
		else {
			if (heap.empty()) {
				std::cout << "CANNOT\n";
			}
			else {
				std::cout << heap.top() << "\n";
				heap.pop();
			}
		}
	}
}