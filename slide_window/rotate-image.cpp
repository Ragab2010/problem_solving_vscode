#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
solution :
1 , 2 , 3 , 
4 , 5 , 6 , 
7 , 8 , 9 , 

--------------
-first we transpose the 2D array :
    Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

1 , 4 , 7 , 
2 , 5 , 8 , 
3 , 6 , 9 , 

--------------
-second we reverse every row : 
    Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

7 , 4 , 1 , 
8 , 5 , 2 , 
9 , 6 , 3 , 

--------------

*/

void rotate2(vector<vector<int>>& matrix) {
    // Transpose the matrix
    for(int rowIndex = 0  ; rowIndex<matrix.size(); rowIndex++ ){
        for(int colIndex = rowIndex  ; colIndex<matrix[rowIndex].size(); colIndex++ ){
            std::swap(matrix[rowIndex][colIndex] , matrix[colIndex][rowIndex]);
        }
    }

    // Reverse each row
    for(int rowIndex = 0  ; rowIndex<matrix.size(); rowIndex++ ){

        std::reverse(matrix[rowIndex].begin() , matrix[rowIndex].end() );
    }

}
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
        for(int rowIndex = 0  ; rowIndex<matrix.size(); rowIndex++ ){
            for(int colIndex = rowIndex  ; colIndex<matrix[rowIndex].size(); colIndex++ ){
                std::swap(matrix[rowIndex][colIndex] , matrix[colIndex][rowIndex]);
            }
        }

    // Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test case 1
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Test Case 1 - Original Matrix:" << endl;
    printMatrix(matrix1);
    rotate(matrix1);
    cout << "Test Case 1 - Rotated Matrix:" << endl;
    printMatrix(matrix1);
    cout << "--------------" << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    cout << "Test Case 2 - Original Matrix:" << endl;
    printMatrix(matrix2);
    rotate(matrix2);
    cout << "Test Case 2 - Rotated Matrix:" << endl;
    printMatrix(matrix2);
    cout << "--------------" << endl;

    // Additional test case 3
    vector<vector<int>> matrix3 = {{1}};
    cout << "Test Case 3 - Original Matrix:" << endl;
    printMatrix(matrix3);
    rotate(matrix3);
    cout << "Test Case 3 - Rotated Matrix:" << endl;
    printMatrix(matrix3);
    cout << "--------------" << endl;

    // Additional test case 4
    vector<vector<int>> matrix4 = {{1, 2}, {3, 4}};
    cout << "Test Case 4 - Original Matrix:" << endl;
    printMatrix(matrix4);
    rotate(matrix4);
    cout << "Test Case 4 - Rotated Matrix:" << endl;
    printMatrix(matrix4);
    cout << "--------------" << endl;

    return 0;
}
