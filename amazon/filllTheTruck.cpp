/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes,
where boxTypes[i] = [numberOfBoxes , numberOfUnitsPerBox ]:

- numberOfBoxes is the number of boxes of type i.
- numberOfUnitsPerBox is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes that can be put on the
truck. 
You can choose any boxes to put on the truck as long as the number of boxes does not
exceed truckSize.
Return the maximum total number of units that can be put on the truck

Example 1:
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
Constraints:
1 <= boxTypes.length <= 1000
1 <= numberOfBoxes , numberOfUnitsPerBox  <= 1000
1 <= truckSize <= 10^6
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparison function to sort box types in descending order based on the number of units per box
bool compareBoxes(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] > b[1];
}

// Function to calculate the maximum total number of units that can be put on the truck
int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    // Sort box types in descending order based on the number of units per box
    std::sort(boxTypes.begin(), boxTypes.end(), compareBoxes);
    cout<<endl;
    for(auto & a :boxTypes ){
        for(auto & b :a ){
            cout<< b<<" , ";
        }
        cout<<endl;
    }
    int maxUnits = 0;

    // Iterate through the sorted box types
    for (const auto& box : boxTypes) {
        // Take as many boxes as possible without exceeding the truck size
        int boxesToTake = std::min(truckSize, box[0]);
        cout<<"boxesToTake ="<<boxesToTake<<endl;
        // Calculate the total units for the current box type
        maxUnits += boxesToTake * box[1];
        cout<<"maxUnits ="<<maxUnits<<endl;

        // Update the available truck space
        truckSize -= boxesToTake;
        cout<<"truckSize ="<<truckSize<<endl;

        // If the truck is full, exit the loop
        if (truckSize == 0) {
            break;
        }
    }

    return maxUnits;
}


int main(){
    cout<<"---Maximum Units on Trank---"<<endl;
    std::vector<std::vector<int>> boxTypes1 = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize1 = 4;
    std::cout << "Example 1: " << maximumUnits(boxTypes1, truckSize1) << std::endl;

    std::vector<std::vector<int>> boxTypes2 = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int truckSize2 = 10;
    std::cout << "Example 2: " << maximumUnits(boxTypes2, truckSize2) << std::endl;

    return 0;
}