#include <iostream>
#include <vector>
#include <deque>

using namespace std;

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
