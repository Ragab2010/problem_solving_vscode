#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Quadruple Sum to Target (medium) #
Given an array of unsorted numbers and a target number, 
find all unique quadruplets in it, whose sum is equal to the target number.
Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.

*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int numsSize = nums.size();
        
        if (numsSize < 4) {
            return result;
        }
        
        sort(nums.begin(), nums.end()); // Sort the array
        
        for (int fixedIndex1 = 0; fixedIndex1 < numsSize - 3; fixedIndex1++) {
            // Skip duplicates for the first fixed index
            if (fixedIndex1 > 0 && nums[fixedIndex1] == nums[fixedIndex1 - 1]) {
                continue;
            }
            for (int fixedIndex2 = fixedIndex1 + 1; fixedIndex2 < numsSize - 2; fixedIndex2++) {
                // Skip duplicates for the second fixed index
                if (fixedIndex2 > fixedIndex1 + 1 && nums[fixedIndex2] == nums[fixedIndex2 - 1]) {
                    continue;
                }
                int leftIndex = fixedIndex2 + 1;
                int rightIndex = numsSize - 1;
                while (leftIndex < rightIndex) {
                    long long sum = (long long)nums[fixedIndex1] + nums[fixedIndex2] + nums[leftIndex] + nums[rightIndex];
                    if (sum == target) {
                        result.push_back({nums[fixedIndex1], nums[fixedIndex2], nums[leftIndex], nums[rightIndex]});
                        leftIndex++;
                        rightIndex--;
                        // Skip duplicates for the third and fourth indices
                        while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]) {
                            leftIndex++;
                        }
                        while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]) {
                            rightIndex--;
                        }
                    } else if (sum < target) {
                        leftIndex++;
                    } else {
                        rightIndex--;
                    }
                }
            }
        }
        
        return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    for (const auto& quad : result) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); ++i) {
            cout << quad[i];
            if (i < quad.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    cout << "Test Case 1:" << endl;
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    printResult(result1);

    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    cout << "Test Case 2:" << endl;
    vector<vector<int>> result2 = sol.fourSum(nums2, target2);
    printResult(result2);

    vector<int> nums3 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target3 = 0;
    cout << "Test Case 3:" << endl;
    vector<vector<int>> result3 = sol.fourSum(nums3, target3);
    printResult(result3);

    vector<int> nums4 = {-3, -1, 0, 2, 4, 5};
    int target4 = 2;
    cout << "Test Case 4:" << endl;
    vector<vector<int>> result4 = sol.fourSum(nums4, target4);
    printResult(result4);

    vector<int> nums5 = {1, 2, 3, 4, -1, -2, -3, -4, 0};
    int target5 = 0;
    cout << "Test Case 5:" << endl;
    vector<vector<int>> result5 = sol.fourSum(nums5, target5);
    printResult(result5);

    return 0;
}
