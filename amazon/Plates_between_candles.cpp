#include <iostream>
#include <vector>

using namespace std;

vector<int> countPlatesBetweenCandles(const string& s, const vector<vector<int>>& queries) {
    vector<int> answer;

    for (const auto& query : queries) {
        int left = query[0];
        int right = query[1];
        int plateCount = 0;

        // Iterate over the substring and count plates between candles
        for (int i = left + 1; i < right; ++i) {
            if (s[i] == '*') {
                int leftCandle = i - 1;
                int rightCandle = i + 1;

                while (leftCandle >= left && s[leftCandle] != '|') {
                    --leftCandle;
                }

                while (rightCandle <= right && s[rightCandle] != '|') {
                    ++rightCandle;
                }

                if (leftCandle >= left && rightCandle <= right) {
                    ++plateCount;
                }
            }
        }

        answer.push_back(plateCount);
    }

    return answer;
}

int main() {
    // Example 1
    string s1 = "**|**|***|";
    vector<vector<int>> queries1 = {{2, 5}, {5, 9}};
    vector<int> result1 = countPlatesBetweenCandles(s1, queries1);

    cout << "Example 1 Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Example 2
    string s2 = "***|**|*****|**||**|*";
    vector<vector<int>> queries2 = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    vector<int> result2 = countPlatesBetweenCandles(s2, queries2);

    cout << "Example 2 Output: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i];
        if (i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
