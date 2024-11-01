#include <iostream>
#include <vector>
#include <algorithm>

struct Volunteer
{
    long long minutesToInflate;
    long long balloonsToRest;
    long long minutesOfRest;
};

long long BalloonsByVolunteer(long long time, const Volunteer& volunteer) {
    long long periodTime = volunteer.minutesToInflate * volunteer.balloonsToRest + volunteer.minutesOfRest;
    long long periodsOfInfalating = time / periodTime;
    long long remainingTime = time % periodTime;
    return periodsOfInfalating * volunteer.balloonsToRest +
        std::min(remainingTime / volunteer.minutesToInflate, volunteer.balloonsToRest);
}

bool check(long long time, const std::vector<Volunteer>& volunteers, long long n) {
    long long res = 0;
    for (const Volunteer& volunteer : volunteers) {
        res += BalloonsByVolunteer(time, volunteer);
    }
    return res >= n;
}

int main() {
    long long balloonsAmount, volunteersAmount;
    std::cin >> balloonsAmount >> volunteersAmount;

    std::vector<Volunteer> volunteers;

    for (int i = 0; i != volunteersAmount; ++i) {
        long long t, z, y;
        std::cin >> t >> z >> y;
        volunteers.push_back({ t, z, y });
    }

    long long left = -1;
    long long right = 1e8;

    while (right - left > 1) {
        unsigned long long mid = (right + left) / 2;
        if (check(mid, volunteers, balloonsAmount)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    long long minTime = right;

    std::vector<long long> result;
    long long totalBalloons = 0;
    for (long long i = 0; i < volunteersAmount; ++i) {
        result.push_back(BalloonsByVolunteer(minTime, volunteers[i]));
        totalBalloons += result.back();
    }

    long long excessBalloons = totalBalloons - balloonsAmount;
    for (long long i = 0; i < volunteersAmount && excessBalloons > 0; ++i) {
        long long reduce = std::min(result[i], excessBalloons);
        result[i] -= reduce;
        excessBalloons -= reduce;
    }

    std::cout << minTime << "\n";

    for (long long i = 0; i < volunteersAmount; ++i) {
        std::cout << result[i] << " ";
    }
}