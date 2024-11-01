#include <iostream>
#include <unordered_set>
#include <list>
#include <vector>
#include <queue>

int main() {
    int n, k, p;
    std::cin >> n >> k >> p;

    std::list<int> carIndexesInRequests[n];
    std::vector<int> carNumberRequest(p);
    for (int i = 0; i < p; i++) {
        std::cin >> carNumberRequest[i];
        carIndexesInRequests[--carNumberRequest[i]].push_back(i);
    }

    int operationsAmount = 0;
    std::unordered_set<int> cars;
    std::priority_queue<std::pair<int, int>> carsNextIndexes;
    for (int i = 0; i < p; i++) {
        int currentCar = carNumberRequest[i];
        carIndexesInRequests[currentCar].pop_front();

        if (cars.find(currentCar) == cars.end()) {
            if (cars.size() >= k) {
                cars.erase(carsNextIndexes.top().second);
                carsNextIndexes.pop();
            }
            operationsAmount++;
            cars.insert(currentCar);
        }

        if (carIndexesInRequests[currentCar].empty()) {
            carsNextIndexes.push({ p, currentCar });
        }
        else {
            carsNextIndexes.push({ carIndexesInRequests[currentCar].front(), currentCar });
        }
    }

    std::cout << operationsAmount;
}