#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
14. Longest Common Prefix
Description
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
Solutions
https://www.youtube.com/watch?v=fhyIORFDD0k
*/
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    int numberOfString = strs.size();
    /*     0       1       2
        "flower","flow","flight"
    */
    //we will take the first string for compare his alphabet with other strings
    /*     0    
        "flower"
    */
    for (int indexOfRefStr = 0; indexOfRefStr < strs[0].size(); ++indexOfRefStr) {
        /*    1       2
            "flow","flight"
        */
        for(int indexOfOtherStrs = 0 ; indexOfOtherStrs < numberOfString; indexOfOtherStrs++){
            if(strs[indexOfOtherStrs].size() <= indexOfRefStr||
                strs[indexOfOtherStrs][indexOfRefStr] != strs[0][indexOfRefStr]){
                return strs[0].substr(0 ,indexOfRefStr );
            }
        }
    }

    return strs[0];
}

void testLongestCommonPrefix() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Test Case 1 - Expected: fl, Got: " << longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test Case 2 - Expected: \"\", Got: \"" << longestCommonPrefix(strs2) << "\"" << endl;

    vector<string> strs3 = {"interspecies", "interstellar", "interstate"};
    cout << "Test Case 3 - Expected: inter, Got: " << longestCommonPrefix(strs3) << endl;

    vector<string> strs4 = {"throne", "throne"};
    cout << "Test Case 4 - Expected: throne, Got: " << longestCommonPrefix(strs4) << endl;

    vector<string> strs5 = {"throne", "dungeon"};
    cout << "Test Case 5 - Expected: \"\", Got: \"" << longestCommonPrefix(strs5) << "\"" << endl;

    vector<string> strs6 = {"apple"};
    cout << "Test Case 6 - Expected: apple, Got: " << longestCommonPrefix(strs6) << endl;

    vector<string> strs7 = {};
    cout << "Test Case 7 - Expected: \"\", Got: \"" << longestCommonPrefix(strs7) << "\"" << endl;
}

int main() {
    testLongestCommonPrefix();
    return 0;
}
