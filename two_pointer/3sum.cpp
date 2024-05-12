#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int numsSize = nums.size();
    vector<vector<int>> result;

    for (int fixedIndex = 0; fixedIndex < numsSize - 2; fixedIndex++) {
        // Skip if the fixedElement is equal to the previous element to avoid duplicating 3 elements
        if (fixedIndex && nums[fixedIndex] == nums[fixedIndex - 1]) {
            continue;
        }

        int leftIndex = fixedIndex + 1;
        int rightIndex = numsSize - 1;

        while (leftIndex < rightIndex) {
            int sum = nums[fixedIndex] + nums[leftIndex] + nums[rightIndex];
            if (sum == 0) {
                result.push_back({nums[fixedIndex], nums[leftIndex], nums[rightIndex]});
                
                // Skip duplicate elements
                while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex + 1]) leftIndex++;
                while (rightIndex > leftIndex && nums[rightIndex] == nums[rightIndex - 1]) rightIndex--;
                
                leftIndex++, rightIndex--;    
            } else if (sum < 0) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }
    }
    return result;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        vector<vector<int>> result = threeSum(testCases[i]);
        if (result.empty()) {
            cout << "No triplet sums up to 0." << endl;
        } else {
            cout << "Output: ";
            for (const auto& triplet : result) {
                cout << "[";
                for (int j = 0; j < 3; ++j) {
                    cout << triplet[j];
                    if (j < 2) {
                        cout << ",";
                    }
                }
                cout << "] ";
            }
            cout << endl;
        }
    }

    return 0;
}
