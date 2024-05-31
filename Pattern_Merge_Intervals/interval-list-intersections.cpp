#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> ans;
    int firstListSize = firstList.size();
    int secondListSize = secondList.size();
    int firstIndexList = 0, secondIndexList = 0;
        /*  firstList = [[0,2],[5,10],[13,23],[24,25]], 
            secondList = [[1,5],[8,12],[15,24],[25,26]]
            Output:      [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
        */
    while (firstIndexList < firstListSize && secondIndexList < secondListSize) {
                    //we get the left  and right to calculate the Intersection
            /*  firstList = [[0,2],[5,10],[13,23],[24,25]], 
                secondList = [[1,5],[8,12],[15,24],[25,26]]
                left = max( 0 , 1) =1  , right = min(2,5) = 2
                if(left <= right) -> ans.push_back([1,2]);
                if(2 < 5) -> firstIndexList++ else ++secondIndexList;
            */
        int left = max(firstList[firstIndexList][0], secondList[secondIndexList][0]);
        int right = min(firstList[firstIndexList][1], secondList[secondIndexList][1]);

        if (left <= right) ans.push_back({left, right});
        if (firstList[firstIndexList][1] < secondList[secondIndexList][1])
            ++firstIndexList;
        else
            ++secondIndexList;
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
    vector<vector<int>> firstList1 = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList1 = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    cout << "Test Case 1:" << endl;
    cout << "First List: ";
    print2DVector(firstList1);
    cout << "Second List: ";
    print2DVector(secondList1);
    vector<vector<int>> result1 = intervalIntersection(firstList1, secondList1);
    cout << "Output: ";
    print2DVector(result1);
    cout << endl;

    // Test case 2
    vector<vector<int>> firstList2 = {{1, 3}, {5, 9}};
    vector<vector<int>> secondList2 = {};
    cout << "Test Case 2:" << endl;
    cout << "First List: ";
    print2DVector(firstList2);
    cout << "Second List: ";
    print2DVector(secondList2);
    vector<vector<int>> result2 = intervalIntersection(firstList2, secondList2);
    cout << "Output: ";
    print2DVector(result2);
    cout << endl;

    // Additional test case 3
    vector<vector<int>> firstList3 = {{1, 7}, {10, 14}, {16, 18}};
    vector<vector<int>> secondList3 = {{2, 3}, {6, 8}, {11, 12}, {15, 17}};
    cout << "Test Case 3:" << endl;
    cout << "First List: ";
    print2DVector(firstList3);
    cout << "Second List: ";
    print2DVector(secondList3);
    vector<vector<int>> result3 = intervalIntersection(firstList3, secondList3);
    cout << "Output: ";
    print2DVector(result3);
    cout << endl;

    // Additional test case 4
    vector<vector<int>> firstList4 = {};
    vector<vector<int>> secondList4 = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Test Case 4:" << endl;
    cout << "First List: ";
    print2DVector(firstList4);
    cout << "Second List: ";
    print2DVector(secondList4);
    vector<vector<int>> result4 = intervalIntersection(firstList4, secondList4);
    cout << "Output: ";
    print2DVector(result4);
    cout << endl;

    return 0;
}
