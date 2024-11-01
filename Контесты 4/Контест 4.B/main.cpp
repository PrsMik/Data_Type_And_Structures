#include <iostream>
#include <vector>

template <typename T>
class MinHeap {
private:
	std::vector<T> heap;

	void SiftUp(int ind) {
		int parent = (ind - 1) / 2;
		while (heap[ind] < heap[parent]) {
			std::swap(heap[ind], heap[parent]);
			parent = (parent - 1) / 2;
			ind = (ind - 1) / 2;
		}
	}

	void SiftDown(int i) {
		while (2 * i + 1 < heap.size()) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			if (left >= heap.size()) {
				return;
			}
			if (right == heap.size()) {
				right = left;
			}
			int j = heap[right] < heap[left] ? right : left;
			if (heap[j] < heap[i]) {
				std::swap(heap[j], heap[i]);

			}
			i = j;
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
	MinHeap<int> heap;
	int n;
	int x;
	std::cin >> n;

	for (int i = 0; i != n; ++i) {
		std::cin >> x;
		heap.Insert(x);
	}

	for (int i = 0; i != n; ++i) {
		std::cout << heap.Extract() << " ";
	}
}