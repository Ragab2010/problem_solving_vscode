#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> freq;
    for (int index = 0; index < nums.size(); ++index) {
        int firstNumber = nums[index]; //frist Number 
        int secondNumber = target - firstNumber;//the second number missing
        if (freq.find(secondNumber) != freq.end()) {
            //index-> the index of the firstNmuber
            //freq[secondNumber]-> the index of the second number 
            //because we use : freq[firstNmuber] =index; to store
            return {index, freq[secondNumber]};
        }
        freq[firstNumber] = index;//add the number at freq
    }
    return {};
}

int main() {
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Input: [2, 7, 11, 15], Target: 9" << endl;
    cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Input: [3, 2, 4], Target: 6" << endl;
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl << endl;

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = twoSum(nums3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Input: [3, 3], Target: 6" << endl;
    cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl << endl;

    // Additional test case 4
    vector<int> nums4 = {1, 5, 7, 8};
    int target4 = 13;
    vector<int> result4 = twoSum(nums4, target4);
    cout << "Test Case 4:" << endl;
    cout << "Input: [1, 5, 7, 8], Target: 13" << endl;
    cout << "Output: [" << result4[0] << ", " << result4[1] << "]" << endl << endl;

    // Additional test case 5
    vector<int> nums5 = {10, 20, 30, 40, 50};
    int target5 = 70;
    vector<int> result5 = twoSum(nums5, target5);
    cout << "Test Case 5:" << endl;
    cout << "Input: [10, 20, 30, 40, 50], Target: 70" << endl;
    cout << "Output: [" << result5[0] << ", " << result5[1] << "]" << endl << endl;

    return 0;
}
