/*Maximize Score after N Operations
Maximize Score After N Operations/Number Game Solution
Amazon OA 2021

You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
In the i operation (1-indexed), you will:

- Choose two elements, x and y.
- Receive a score of i * gcd(x, y).
- Remove x and y from nums.

Return the maximum score you can receive after performing n operations.
The function gcd(x, y) is the greatest common divisor of x and y.

Example 1:
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

Example 2:
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

Example 3:
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

Constraints:
1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 10^6
*/


// int maxScoreTest(vector<int>& nums) {
//     int gcd_max = 0;

//     while (nums.size() > 1) {
//         map<int, pair<int, int>, std::greater<int>> myMap;

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 int gcd_result = gcd(nums[i], nums[j]) * (i + 1);
//                 myMap[gcd_result] = make_pair(i, j);
//             }
//         }

//         gcd_max += myMap.begin()->first;
//         int firstIndex = myMap.begin()->second.first;
//         int secondIndex = myMap.begin()->second.second;

//         nums.erase(begin(nums) + max(firstIndex, secondIndex));
//         nums.erase(begin(nums) + min(firstIndex, secondIndex));
//     }

//     return gcd_max;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
/*prefer*/
int maxScore1(vector<int>& nums) {
    int n = nums.size() / 2;
    
    // Create a 2D DP array to store intermediate results
    vector<vector<int>> dp(n + 1, vector<int>(1 << (2 * n), 0));

    // Iterate over the number of operations
    for (int i = 1; i <= n; ++i) {
        // Iterate over all possible states
        for (int state = 0; state < (1 << (2 * n)); ++state) {
            // Iterate over all pairs of elements
            for (int j = 0; j < 2 * n; ++j) {
                if (!(state & (1 << j))) {
                    for (int k = j + 1; k < 2 * n; ++k) {
                        if (!(state & (1 << k))) {
                            // Calculate the new state and update the maximum score
                            int newState = state | (1 << j) | (1 << k);
                            dp[i][newState] = max(dp[i][newState], dp[i - 1][state] + i * gcd(nums[j], nums[k]));
                        }
                    }
                }
            }
        }
    }

    // The answer is the maximum score after n operations
    return *max_element(dp[n].begin(), dp[n].end());
}
/*prefer this */
int maxScore2(vector<int>& nums) {
    int n = nums.size() / 2;

    // Create a 1D DP array to store intermediate results
    vector<int> dp(1 << (2 * n), 0);

    // Iterate over the number of operations
    for (int i = 1; i <= n; ++i) {
        // Create a temporary array to store updated values
        vector<int> temp(1 << (2 * n), 0);

        // Iterate over all possible states
        for (int state = 0; state < (1 << (2 * n)); ++state) {
            // Iterate over all pairs of elements
            for (int j = 0; j < 2 * n; ++j) {
                if (!(state & (1 << j))) {
                    for (int k = j + 1; k < 2 * n; ++k) {
                        if (!(state & (1 << k))) {
                            // Calculate the new state and update the maximum score
                            int newState = state | (1 << j) | (1 << k);
                            temp[newState] = max(temp[newState], dp[state] + i * gcd(nums[j], nums[k]));
                        }
                    }
                }
            }
        }

        // Copy the updated values from temp to dp
        dp = temp;
    }

    // The answer is the maximum score after n operations
    return *max_element(dp.begin(), dp.end());
}

/**recursion one : not acceptance ****/
int maxScoreHelper(vector<int>& nums, int idx, vector<bool>& chosen, int operations) {
    if (operations == 0) {
        return 0;
    }

    int maxScore = 0;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (!chosen[i] && !chosen[j]) { //chosen vector at index i , j == zero
                chosen[i] = true;
                chosen[j] = true;

                int score = operations * gcd(nums[i], nums[j]);
                maxScore = max(maxScore, score + maxScoreHelper(nums, idx + 1, chosen, operations - 1));

                chosen[i] = false;
                chosen[j] = false;
            }
        }
    }

    return maxScore;
}

int maxScore(vector<int>& nums) {
    int n = nums.size() / 2;
    vector<bool> chosen(nums.size(), false);

    return maxScoreHelper(nums, 0, chosen, n);
}


/*recursion accept*/
int maxScoreHelper(vector<int>& nums, int idx, vector<bool>& token, int operation, unordered_map<long long, int>& memo) {
    if (operation == 0) {
        return 0;
    }

    long long key = 0;
    for (int i = 0; i < nums.size(); i++) {
        key = key * 2 + token[i];
    }

    if (memo.count(key)) {
        return memo[key];
    }

    int max_score = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (!token[i] && !token[j]) {
                token[i] = true;
                token[j] = true;
                int score = operation * gcd(nums[i], nums[j]);
                max_score = max(
                    max_score,
                    score + maxScoreHelper(nums, idx + 1, token, operation - 1, memo)
                );
                token[i] = false;
                token[j] = false;
            }
        }
    }

    memo[key] = max_score;
    return max_score;
}

int maxScore(vector<int>& nums) {
    int n = nums.size() / 2;
    vector<bool> token(n, false);
    unordered_map<long long, int> memo;
    return maxScoreHelper(nums, 0, token, n, memo);
}

int main() {
    vector<int> nums = {925612, 737192, 813525, 707250};
    cout << "Output: " << maxScore(nums) << endl;  // Expected: 154

    return 0;
}
