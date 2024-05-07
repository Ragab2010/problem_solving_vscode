#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int numsSize = nums.size();
    int nextNonDuplicatedIndex = 0;
    int forwardIndex = 1;
    while (forwardIndex < numsSize) {
        if (nums[nextNonDuplicatedIndex] != nums[forwardIndex]) {
            nextNonDuplicatedIndex++;
            nums[nextNonDuplicatedIndex] = nums[forwardIndex];
        }
        forwardIndex++;
    }
    return nextNonDuplicatedIndex + 1;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {1, 1, 2},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
    };
    
    vector<int> expectedOutputs = {2, 5};

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i];
        int expectedLength = expectedOutputs[i];
        
        int actualLength = removeDuplicates(nums);

        cout << "Test Case " << i+1 << ":" << endl;
        cout << "Input: ";
        for (int num : testCases[i]) {
            cout << num << " ";
        }
        cout << endl;
        
        cout << "Expected Length: " << expectedLength << endl;
        cout << "Actual Length: " << actualLength << endl;

        if (actualLength == expectedLength) {
            cout << "Test Passed!" << endl << endl;
        } else {
            cout << "Test Failed!" << endl << endl;
        }
    }

    return 0;
}
