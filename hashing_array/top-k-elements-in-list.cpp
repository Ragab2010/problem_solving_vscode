#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequencies
    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Step 2: Use a min-heap to keep track of the top k elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto& entry : frequencyMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 3: Extract the top k elements
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    // The elements in the result vector are currently in ascending order of frequency
    // We can reverse it if needed, though the order in the final answer doesn't matter
    reverse(result.begin(), result.end());

    return result;
}

void printResult(const vector<int>& result) {
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

void testTopKFrequent() {
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    int k1 = 2;
    cout << "Test Case 1:" << endl;
    printResult(topKFrequent(nums1, k1));  // Expected output: [2, 3]

    vector<int> nums2 = {7, 7};
    int k2 = 1;
    cout << "Test Case 2:" << endl;
    printResult(topKFrequent(nums2, k2));  // Expected output: [7]

    vector<int> nums3 = {1, 1, 1, 2, 2, 3};
    int k3 = 2;
    cout << "Test Case 3:" << endl;
    printResult(topKFrequent(nums3, k3));  // Expected output: [1, 2]

    vector<int> nums4 = {4, 4, 4, 4, 5, 5, 6};
    int k4 = 2;
    cout << "Test Case 4:" << endl;
    printResult(topKFrequent(nums4, k4));  // Expected output: [4, 5]

    vector<int> nums5 = {-1, -1, -1, 2, 2, 3};
    int k5 = 3;
    cout << "Test Case 5:" << endl;
    printResult(topKFrequent(nums5, k5));  // Expected output: [-1, 2, 3]
}

int main() {
    testTopKFrequent();
    return 0;
}
