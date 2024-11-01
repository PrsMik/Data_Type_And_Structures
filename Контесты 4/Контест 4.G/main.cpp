#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> poolsPopulations(n);
    auto cmp = [](std::pair<int, int> lhs, std::pair<int, int> rhs) { return lhs.first > rhs.first; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> heap(cmp);
    for (int i = 0; i < n; ++i) {
        std::cin >> poolsPopulations[i];
        heap.push({ std::max(1000 - poolsPopulations[i], 1), i });
    }

    int currentPool = 0;
    int currentTime = 0;

    while (std::abs(currentPool - heap.top().second) + currentTime <= heap.top().first) {
        currentPool = heap.top().second;
        currentTime = heap.top().first;
        heap.pop();
        ++poolsPopulations[currentPool];
        heap.push({ currentTime + std::max(1000 - poolsPopulations[currentPool], 1), currentPool });
    }

    std::cout << heap.top().first;
}