#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> freq;
    for (int index = 0; index < nums.size(); index++) {
        int expectTarget = target - nums[index];
        if (freq.find(expectTarget) != freq.end()) {
            return {freq[expectTarget], index};
        }
        freq[nums[index]] = index;
    }
    return {};
}

int main() {
    // Test cases
    vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6}
    };

    vector<vector<int>> expectedOutputs = {{0, 1}, {1, 2}, {0, 1}};

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int target = testCases[i].second;
        vector<int> expectedIndices = expectedOutputs[i];

        vector<int> actualIndices = twoSum(nums, target);

        cout << "Test Case " << i+1 << ":" << endl;
        cout << "Input: nums = [";
        for (int j = 0; j < nums.size(); ++j) {
            cout << nums[j];
            if (j < nums.size() - 1) {
                cout << ", ";
            }
        }
        cout << "], target = " << target << endl;

        cout << "Expected Output: [";
        for (int j = 0; j < expectedIndices.size(); ++j) {
            cout << expectedIndices[j];
            if (j < expectedIndices.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        cout << "Actual Output: [";
        for (int j = 0; j < actualIndices.size(); ++j) {
            cout << actualIndices[j];
            if (j < actualIndices.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        if (actualIndices == expectedIndices) {
            cout << "Test Passed!" << endl << endl;
        } else {
            cout << "Test Failed!" << endl << endl;
        }
    }

    return 0;
}
