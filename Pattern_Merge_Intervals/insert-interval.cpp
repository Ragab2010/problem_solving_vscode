#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/*
Solutions
Solution 1: Sorting + Interval Merging

We can first add the new interval newInterval to the interval list intervals, and then merge according to the regular method of interval merging.

The time complexity is 
, and the space complexity is 
. Here, 
 is the number of intervals.

Solution 2: One-pass Traversal

We can traverse the interval list intervals, let the current interval be interval, and there are three situations for each interval:

The current interval is on the right side of the new interval, that is, 
. At this time, if the new interval has not been added, then add the new interval to the answer, and then add the current interval to the answer.
The current interval is on the left side of the new interval, that is, 
. At this time, add the current interval to the answer.
Otherwise, it means that the current interval and the new interval intersect. We take the minimum of the left endpoint of the current interval and the left endpoint of the new interval, and the maximum of the right endpoint of the current interval and the right endpoint of the new interval, as the left and right endpoints of the new interval, and then continue to traverse the interval list.
After the traversal, if the new interval has not been added, then add the new interval to the answer.

The time complexity is 
, where 
 is the number of intervals. Ignoring the space consumption of the answer array, the space complexity is 
.


*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.emplace_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (ans.back()[1] < intervals[i][0]) {
            ans.emplace_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.emplace_back(newInterval);
    return merge(intervals);
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
    vector<int> newInterval1 = {4, 9};
    cout << "Test Case 1:" << endl;
    cout << "Input intervals: ";
    print2DVector(intervals1);
    cout << "New interval: [" << newInterval1[0] << "," << newInterval1[1] << "]" << endl;
    vector<vector<int>> result1 = insert(intervals1, newInterval1);
    cout << "Output: ";
    print2DVector(result1);
    cout << endl;

    // Test case 2
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<int> newInterval2 = {0, 3};
    cout << "Test Case 2:" << endl;
    cout << "Input intervals: ";
    print2DVector(intervals2);
    cout << "New interval: [" << newInterval2[0] << "," << newInterval2[1] << "]" << endl;
    vector<vector<int>> result2 = insert(intervals2, newInterval2);
    cout << "Output: ";
    print2DVector(result2);
    cout << endl;

    // Additional test case 3
    vector<vector<int>> intervals3 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval3 = {4, 8};
    cout << "Test Case 3:" << endl;
    cout << "Input intervals: ";
    print2DVector(intervals3);
    cout << "New interval: [" << newInterval3[0] << "," << newInterval3[1] << "]" << endl;
    vector<vector<int>> result3 = insert(intervals3, newInterval3);
    cout << "Output: ";
    print2DVector(result3);
    cout << endl;

    // Additional test case 4
    vector<vector<int>> intervals4 = {{1, 5}};
    vector<int> newInterval4 = {0, 3};
    cout << "Test Case 4:" << endl;
    cout << "Input intervals: ";
    print2DVector(intervals4);
    cout << "New interval: [" << newInterval4[0] << "," << newInterval4[1] << "]" << endl;
    vector<vector<int>> result4 = insert(intervals4, newInterval4);
    cout << "Output: ";
    print2DVector(result4);
    cout << endl;

    return 0;
}
