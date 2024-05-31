#include <iostream>
#include <vector>
#include <deque>

using namespace std;
/*
Description
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.

You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:

You may assume k is always valid, 1 ≤ k ≤ input array’s size for non-empty array.

Follow up:

Could you solve it in linear time?

Algorithm
Use a double-ended queue (deque) that allows insertion and deletion operations at both ends in O(1) time complexity. To maintain a sliding window of size k, store indices instead of actual numbers in the deque.

For the first k elements from nums, add them directly to the deque. Before adding each new element, compare it with the element at the back of the deque (if the last element in the deque is index i, the corresponding number is nums[i]). If the current number is greater, remove the last element from the deque. Continue this process until either the deque is empty or the last element in the deque is greater than or equal to the current number. The index of the maximum element in the first window of size k is at the front of the deque. Add this maximum element to the result array at index 0.

Then, iterate over nums starting from index k to the end. For each index i, first check if the first element in the deque equals i - k (which means it’s outside the current window) and remove it if necessary. Next, if the number corresponding to the last index in the deque is less than the current number, remove the last element from the deque. Repeat until the deque is empty or the number corresponding to the last element in the deque is greater than or equal to the current number. The index of the maximum element in the current window is at the front of the deque. Place this maximum element in the corresponding position of the result array.

Finally, return the result array.

Example Illustration:
Given the input: [1, 3, -1, -3, 5, 3, 6, 7]

Use a deque q with the right end for insertion and the left front for deletion.
iteration-1: q = [0]
iteration-2: q = [0, 1]
iteration-3: q = [0, 1, 2]

At iteration-4: Remove the front if it’s out of the window: q = [1, 2]. Keep removing from the back if the current number is greater: none. Add the current index: q = [1, 2, 3]. The maximum is nums[1].

At iteration-5: Check and remove the front if it’s out of the window: q = [2, 3]. Remove from the back if the current number is greater, resulting in: q = []. Then, add the current index: q = [4]. The maximum is nums[4].

iteration-6 to iteration-8: Follow the same procedure to update the deque and identify the maximum for each window, updating the result array accordingly.
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;
    int sizeNums = nums.size();
    int endWindow = 0, startWindow = 0;
    while (endWindow < sizeNums) {
        //geep the deque update with the greater element of slide window of nums
        /*here we check if element at deque (the index of element of nums)
            is not greate than(less than) the next element at slide window 
            nums[endWindow] , so we pop it , only the great element are push */
        if(dq.empty() == false && nums[dq.back()] < nums[endWindow]){
            dq.pop_back();// pop_back this nums[dq.back()]
            continue;
        }
        //push the index of the right element of silde window
        dq.push_back(endWindow);

        //shrink the slide window at deque to be from [startWindow to endWindow ]
        if(dq.empty() == false && dq.front() < startWindow){
            dq.pop_front();
            continue;
        }
        /*if the slide window is equl or greate then k , so
            push_back the  nums[dq.front()] is the from of deque is always greater
        */
        if(endWindow - startWindow + 1 >= k){
            result.push_back(nums[dq.front()]);
            startWindow++;
        }
        endWindow++;
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
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(nums1);
    cout << "Output: ";
    printVector(maxSlidingWindow(nums1, k1));
    cout << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    printVector(nums2);
    cout << "Output: ";
    printVector(maxSlidingWindow(nums2, k2));
    cout << endl;

    return 0;
}
