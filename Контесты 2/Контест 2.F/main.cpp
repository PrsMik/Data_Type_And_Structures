#include <iostream>
#include <queue>

struct SlidingWindow {
	std::deque<int> deq;

	void push_back(int& addedElement) {
		while (!deq.empty() && deq.back() > addedElement) {
			deq.pop_back();
		}
		deq.push_back(addedElement);
	}

	void pop_front(int& removed_element) {
		if (!deq.empty() && deq.front() == removed_element)
			deq.pop_front();
	}

	int get_min() {
		return deq.front();
	}
};


int main() {
	int n, k;

	std::cin >> n >> k;

	std::queue<int> numbers;
	SlidingWindow window;

	for (int i = 1; i <= n; ++i) {
		int x;
		std::cin >> x;
		numbers.push(x);
		window.push_back(x);
		if (i >= k) {
			std::cout << window.get_min() << "\n";
			window.pop_front(numbers.front());
			numbers.pop();
		}
	}
}