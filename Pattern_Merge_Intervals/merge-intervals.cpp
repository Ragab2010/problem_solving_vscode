#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Solutions
Solution 1: Sorting + One-pass Traversal

We can sort the intervals in ascending order by the left endpoint, and then traverse the intervals for merging operations.

The specific merging operation is as follows.

First, we add the first interval to the answer. Then, we consider each subsequent interval in turn:

If the right endpoint of the last interval in the answer array is less than the left endpoint of the current interval, it means that the two intervals will not overlap, so we can directly add the current interval to the end of the answer array;
Otherwise, it means that the two intervals overlap. We need to use the right endpoint of the current interval to update the right endpoint of the last interval in the answer array, setting it to the larger of the two.
Finally, we return the answer array.

The time complexity is 
, and the space complexity is 
. Here, 
 is the number of intervals.

Example Input
Consider the following list of intervals: [[1,3],[2,6],[8,10],[15,18]]. These intervals represent parts of a line with start and end points.

Sort Intervals: First, the code sorts the intervals based on their start values. For our example, the intervals are already sorted, so the sorted list remains [[1,3],[2,6],[8,10],[15,18]].

Initialization: An empty list ans is initialized to store the merged intervals.

Iteration and Merging:

The code iterates through the sorted intervals.
For the first interval [1,3], ans is empty, so the interval is directly appended to ans.
Next interval, [2,6], overlaps with [1,3] since 3 >= 2. So, we merge them by updating the end of the last interval in ans to max(3, 6) = 6. Now, ans = [[1,6]].
The next interval [8,10] does not overlap with [1,6] because 6 < 8. So, [8,10] is appended to ans, resulting in ans = [[1,6], [8,10]].
Similarly, [15,18] doesn’t overlap with the last interval in ans ([8,10]), so it’s also appended to ans. The final ans is [[1,6], [8,10], [15,18]].
The function returns the merged intervals: [[1,6],[8,10],[15,18]]. This means we have three ranges where the intervals overlap or are continuous without gaps.

*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    //[[1,3],[2,6],[8,10],[15,18]]
    vector<vector<int>> ans;
    ans.emplace_back(intervals[0]);//[1,3]
    for(int intervalIndex = 1 ; intervalIndex < intervals.size() ;intervalIndex++){
        /*ans = [1,3]     intervals= [2,6],[8,10],[15,18]
        3 < 2 == false so we merge them by updating the end of the last interval ans to max(3, 6) = 6. Now,
        6 < 8 == true So, [8,10] is appended to ans, resulting in ans = [[1,6], [8,10]].
        */
        if(ans.back()[1] < intervals[intervalIndex][0]){
            ans.emplace_back(intervals[intervalIndex]);
        }else{
            ans.back()[1]=std::max(ans.back()[1] , intervals[intervalIndex][1]);
        }
    }

    return ans;
}

// Function to print a 2D vector
void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& interval : vec) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    // Test case 1
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    print2DVector(intervals1);
    vector<vector<int>> result1 = merge(intervals1);
    cout << "Output: ";
    print2DVector(result1);
    cout << endl;

    // Test case 2
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    print2DVector(intervals2);
    vector<vector<int>> result2 = merge(intervals2);
    cout << "Output: ";
    print2DVector(result2);
    cout << endl;

    // Additional test case 3
    vector<vector<int>> intervals3 = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    cout << "Test Case 3:" << endl;
    cout << "Input: ";
    print2DVector(intervals3);
    vector<vector<int>> result3 = merge(intervals3);
    cout << "Output: ";
    print2DVector(result3);
    cout << endl;

    // Additional test case 4
    vector<vector<int>> intervals4 = {{1, 5}, {2, 3}, {4, 6}};
    cout << "Test Case 4:" << endl;
    cout << "Input: ";
    print2DVector(intervals4);
    vector<vector<int>> result4 = merge(intervals4);
    cout << "Output: ";
    print2DVector(result4);
    cout << endl;

    return 0;
}
