#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int numsSize = nums.size();
    vector<int> result(numsSize);
    int leftIndex = 0 ; 
    int rightIndex = numsSize - 1;
    int resultIndex = numsSize - 1; // to fill the vector result from back
    while (leftIndex <= rightIndex) { // <= to check the middle
        int leftSquare  = nums[leftIndex]  * nums[leftIndex];
        int rightSquare = nums[rightIndex] * nums[rightIndex];
        if (leftSquare > rightSquare) {
            result[resultIndex] = leftSquare;
            leftIndex++;
        } else {
            result[resultIndex] = rightSquare;
            rightIndex--;
        }
        resultIndex--;
    }
    return result;
}

// Function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test cases
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(nums1);
    cout << "Output: ";
    printVector(sortedSquares(nums1));
    cout << endl;

    vector<int> nums2 = {-7, -3, 2, 3, 11};
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    printVector(nums2);
    cout << "Output: ";
    printVector(sortedSquares(nums2));
    cout << endl;

    return 0;
}
