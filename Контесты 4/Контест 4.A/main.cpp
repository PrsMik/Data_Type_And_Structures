#include <iostream>
#include <vector>

template <typename T>
class MaxHeap {
private:
	std::vector<T> heap;

	void SiftUp(int ind) {
		int parent = (ind - 1) / 2;
		while (heap[ind] > heap[parent]) {
			std::swap(heap[ind], heap[parent]);
			parent = (parent - 1) / 2;
			ind = (ind - 1) / 2;
		}
	}

	void SiftDown(int ind) {
		int left = 2 * ind + 1;
		int right = 2 * ind + 2;
		if (left < heap.size()) {
			if (heap[ind] < heap[left]) {
				std::swap(heap[ind], heap[left]);
				SiftDown(left);
			}
		}
		if (right < heap.size()) {
			if (heap[ind] < heap[right]) {
				std::swap(heap[ind], heap[right]);
				SiftDown(right);
			}
		}
	}

public:
	void Insert(T elem) {
		heap.push_back(elem);
		SiftUp(heap.size() - 1);
	}

	T Extract() {
		T removed = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		SiftDown(0);
		return removed;
	}
};

int main() {
	MaxHeap<int> heap;
	int n;
	std::cin >> n;

	for (int i = 0; i != n; ++i) {
		int command;
		std::cin >> command;
		if (command == 0) {
			int number;
			std::cin >> number;
			heap.Insert(number);
		}
		else {
			std::cout << heap.Extract() << "\n";
		}
	}
}