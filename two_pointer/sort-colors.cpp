#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;
/*
    75. Sort Colors
    Description
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    

    Example 1:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
    Example 2:

    Input: nums = [2,0,1]
    Output: [0,1,2]
    

    Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.

*/
/*
the idea is to use two pointer
-one pointer for to be before the Zeros
-second pointer for to be before the Twos
-third is the index for traverse the array 
0,0,lowpointer,1,1,highpointer,2,2
*/
void sortColors(vector<int>& nums) {
    int low_afterZero = 0;//to be before the Zeros
    int high_beforeTwo = nums.size() - 1;//to be before the Twos
    int traverseIndex = 0;//for traverse
    //important to the traverse <= high_beforeTwo
    while (traverseIndex <= high_beforeTwo) {
        /*if the nums[traverseIndex] element == 0 , 
        so the element it have to be before the (low_afterZero) pointer, 
        so we swap nums[traverseIndex]  with nums[low_afterZero], 
        and increment low_afterZero++  , to make it after all 0s
        and increment traverseIndex++ to traverse all the array 
        */
        if (nums[traverseIndex] == 0) {
            std::swap(nums[traverseIndex], nums[low_afterZero]);
            traverseIndex++;
            low_afterZero++;
        } else if (nums[traverseIndex] == 1) {
        /*if the nums[traverseIndex] element == 1 , 
        so the element it have to be between  (low_afterZero) pointer and (high_beforeTwo) pointer, 
        so we leave it at middle between them , 
        and increment traverseIndex++ to traverse all the array 
        */
            traverseIndex++;
        } else {
        /*if the nums[traverseIndex] element == 2 , 
        so the element it have to be after the (high_beforeTwo) pointer, 
        so we swap nums[traverseIndex]  with nums[high_beforeTwo], 
        and decrement  high_beforeTwo--  , to make it before all 2s
        and increment traverseIndex++ to traverse all the array 
        */
            std::swap(nums[traverseIndex], nums[high_beforeTwo]);
            high_beforeTwo--;
        }
    }
}

// Function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(nums1);
    sortColors(nums1);
    cout << "Output: ";
    printVector(nums1);
    cout << endl;

    // Test case 2
    vector<int> nums2 = {2, 0, 1};
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    printVector(nums2);
    sortColors(nums2);
    cout << "Output: ";
    printVector(nums2);
    cout << endl;

    // Additional test case 3
    vector<int> nums3 = {1, 2, 0, 0, 1, 2};
    cout << "Test Case 3:" << endl;
    cout << "Input: ";
    printVector(nums3);
    sortColors(nums3);
    cout << "Output: ";
    printVector(nums3);
    cout << endl;

    // Additional test case 4
    vector<int> nums4 = {0, 1, 2};
    cout << "Test Case 4:" << endl;
    cout << "Input: ";
    printVector(nums4);
    sortColors(nums4);
    cout << "Output: ";
    printVector(nums4);
    cout << endl;

    return 0;
}
