#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (const auto& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }
    
    vector<vector<string>> result;
    for (auto& group : anagramGroups) {
        result.push_back(move(group.second));
    }
    
    return result;
}

void printResult(const vector<vector<string>>& result) {
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }
}

void testGroupAnagrams() {
    vector<string> strs1 = {"act", "pots", "tops", "cat", "stop", "hat"};
    cout << "Test Case 1:" << endl;
    printResult(groupAnagrams(strs1));

    vector<string> strs2 = {"x"};
    cout << "Test Case 2:" << endl;
    printResult(groupAnagrams(strs2));

    vector<string> strs3 = {""};
    cout << "Test Case 3:" << endl;
    printResult(groupAnagrams(strs3));

    vector<string> strs4 = {"a", "b", "c", "a"};
    cout << "Test Case 4:" << endl;
    printResult(groupAnagrams(strs4));

    vector<string> strs5 = {"listen", "silent", "enlist", "google", "gogole"};
    cout << "Test Case 5:" << endl;
    printResult(groupAnagrams(strs5));
}

int main() {
    testGroupAnagrams();
    return 0;
}
