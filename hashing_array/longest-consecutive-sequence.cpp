#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
/*
Longest Consecutive Sequence
Given an array of integers nums, return the length of the longest consecutive sequence of elements.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:

Input: nums = [0,3,2,5,4,6,1,1]

Output: 7
Constraints:

0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9



*/
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    for (int n : numSet) {
        if (numSet.find(n - 1) == numSet.end()) {
            int length = 1;
            while (numSet.find(n + length) != numSet.end()) {
                length++;
            }
            longest = max(length, longest);
        }
    }
    return longest;
}

void testLongestConsecutive() {
    vector<int> nums1 = {2, 20, 4, 10, 3, 4, 5};
    cout << "Test Case 1 - Expected: 4, Got: " << longestConsecutive(nums1) << endl;

    vector<int> nums2 = {0, 3, 2, 5, 4, 6, 1, 1};
    cout << "Test Case 2 - Expected: 7, Got: " << longestConsecutive(nums2) << endl;

    vector<int> nums3 = {100, 4, 200, 1, 3, 2};
    cout << "Test Case 3 - Expected: 4, Got: " << longestConsecutive(nums3) << endl;

    vector<int> nums4 = {0, -1};
    cout << "Test Case 4 - Expected: 2, Got: " << longestConsecutive(nums4) << endl;

    vector<int> nums5 = {9, 1, -3, 7, 8, -2, 0, -1, 2, -9, -8, -7, -6, -5, -4, 4, 5, 6, -10};
    cout << "Test Case 5 - Expected: 10, Got: " << longestConsecutive(nums5) << endl;

    vector<int> nums6 = {};
    cout << "Test Case 6 - Expected: 0, Got: " << longestConsecutive(nums6) << endl;

    vector<int> nums7 = {1, 2, 0, 1};
    cout << "Test Case 7 - Expected: 3, Got: " << longestConsecutive(nums7) << endl;
}

int main() {
    testLongestConsecutive();
    return 0;
}
