#include <iostream>
#include <vector>
#include <algorithm>
 #include <numeric>

bool canShipWithinDays(const std::vector<int>& weights, int days, int capacity) {
    int count = 1;
    int currentWeight = 0;

    for (int w : weights) {
        currentWeight += w;
        if (currentWeight > capacity) {
            count++;
            currentWeight = w;
        }
    }

    return count <= days;
}

int shipWithinDays(const std::vector<int>& weights, int days) {
    int left = *std::max_element(weights.begin(), weights.end());
    int right = std::accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canShipWithinDays(weights, days, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    // Example 1
    std::vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    std::cout << "Output 1: " << shipWithinDays(weights1, days1) << std::endl;

    // Example 2
    std::vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    std::cout << "Output 2: " << shipWithinDays(weights2, days2) << std::endl;

    // Example 3
    std::vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    std::cout << "Output 3: " << shipWithinDays(weights3, days3) << std::endl;

    return 0;
}
