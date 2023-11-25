#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > target) {
            continue;  // Skip if the current candidate is greater than the target
        }

        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], current, result, i);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;

    // Start the backtracking process from the beginning of the candidates array
    backtrack(candidates, target, current, result, 0);

    return result;
}

int main() {
    // Example usage:
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = combinationSum(candidates1, target1);

    cout << "Example 1:\n";
    for (const auto& combination : result1) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = combinationSum(candidates2, target2);

    cout << "\nExample 2:\n";
    for (const auto& combination : result2) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    vector<int> candidates3 = {2};
    int target3 = 1;
    vector<vector<int>> result3 = combinationSum(candidates3, target3);

    cout << "\nExample 3:\n";
    for (const auto& combination : result3) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
