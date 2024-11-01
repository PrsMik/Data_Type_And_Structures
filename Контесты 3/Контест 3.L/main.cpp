#include <iostream>
#include <vector>
#include <algorithm>

bool check(std::vector<int>& heights, int comfort, int neededBrigades, int neededMembers) {
    int lastMemberInd = 0;
    int recrutedBrigades = 0;
    while ((static_cast<size_t>(lastMemberInd) + neededMembers - 1) < heights.size()) {
        if ((heights[static_cast<size_t>(lastMemberInd) + neededMembers - 1] - heights[lastMemberInd]) <= comfort) {
            recrutedBrigades += 1;
            lastMemberInd = lastMemberInd + neededMembers;
        }
        else {
            lastMemberInd += 1;
        }
    }
    if (recrutedBrigades >= neededBrigades) {
        return true;
    }
    return false;
}

int main() {
    int n, r, c;
    std::cin >> n >> r >> c;

    std::vector<int> heights;

    for (int ind = 0; ind != n; ++ind) {
        int x;
        std::cin >> x;
        heights.push_back(x);
    }

    std::sort(heights.begin(), heights.end());

    int left = -1;
    int right = heights.back() - heights.front() + 1;


    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(heights, mid, r, c)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    std::cout << right;
}