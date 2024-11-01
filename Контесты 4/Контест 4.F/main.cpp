#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].first >> arr[i].second;
    }

    std::sort(arr.begin(), arr.end());

    int amount = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    for (const auto& item : arr) {
        if (!heap.empty() && heap.top() <= item.first) {
            heap.pop();
        }
        heap.push(item.first + item.second);
        amount = std::max(amount, static_cast<int>(heap.size()));
    }

    std::cout << amount;
}
