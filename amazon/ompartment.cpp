#include <iostream>
#include <vector>

using namespace std;

vector<int> closedCompartments(string s, vector<int>& startIndices, vector<int>& endIndices) {
    int n = s.size();
    vector<int> result;

    for (int i = 0; i < startIndices.size(); ++i) {
        int start = startIndices[i] - 1;  // Convert to 0-based index
        int end = endIndices[i] - 1;      // Convert to 0-based index

        int itemCount = 0;
        int compartmentCount = 0;

        for (int j = start + 1; j <= end; ++j) {
            if (s[j] == '|') {
                compartmentCount += itemCount;
                itemCount = 0;
            } else if (s[j] == '*') {
                itemCount++;
            }
        }

        result.push_back(compartmentCount);
    }

    return result;
}

int main() {
    // Example 1
    string s1 = "|**|*|*";
    vector<int> startIndices1 = {1, 1};
    vector<int> endIndices1 = {5, 6};
    vector<int> result1 = closedCompartments(s1, startIndices1, endIndices1);

    cout << "Example 1 Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Example 2
    string s2 = "*|*|";
    vector<int> startIndices2 = {1};
    vector<int> endIndices2 = {3};
    vector<int> result2 = closedCompartments(s2, startIndices2, endIndices2);

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
