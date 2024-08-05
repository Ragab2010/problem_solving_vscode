#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // This will store all the permutations
        vector<bool> used(nums.size(), false); // Keeps track of which elements are used in the current permutation
        vector<int> permutationSet; // Stores the current permutation being constructed
        backTrack(nums, result, permutationSet, used); // Start backtracking
        return result; // Return the result containing all permutations
    }

    void backTrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutationSet, vector<bool>& used) {
        // If the current permutation set has the same size as the nums array,
        // it means we have a complete permutation
        if (permutationSet.size() == nums.size()) {
            result.push_back(permutationSet); // Add the current permutation to the result
            return;
        }
        
        // Iterate through all elements in the nums array
        for (int elementIndex = 0; elementIndex < nums.size(); elementIndex++) {
            // If the current element is not used in the current permutation
            if (used[elementIndex] == false) {
                used[elementIndex] = true; // Mark the element as used
                int number = nums[elementIndex]; // Get the current number
                permutationSet.push_back(number); // Add it to the current permutation set
                backTrack(nums, result, permutationSet, used); // Recursively generate the remaining permutations
                permutationSet.pop_back(); // Remove the last element to backtrack
                used[elementIndex] = false; // Mark the element as unused for the next iterations
            }
        }
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& perm : result) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
}

// Main function to test the Solution class
int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test Case 1:" << endl;
    vector<vector<int>> result1 = solution.permute(nums1);
    printResult(result1);

    // Test Case 2
    vector<int> nums2 = {0, 1};
    cout << "Test Case 2:" << endl;
    vector<vector<int>> result2 = solution.permute(nums2);
    printResult(result2);

    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Test Case 3:" << endl;
    vector<vector<int>> result3 = solution.permute(nums3);
    printResult(result3);

    return 0;
}
