#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
/*
Description
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.


Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> patternFreq, windowFreq;

    // Populate pattern frequency map
    for (char c : s1)
        patternFreq[c]++;

    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < s2.length(); windowEnd++) {
        char rightChar = s2[windowEnd];

        // Update window frequency map
        windowFreq[rightChar]++;

        // Shrink the window if it's larger than pattern size
        if (windowEnd - windowStart + 1 > s1.length()) {
            char leftChar = s2[windowStart++];
            windowFreq[leftChar]--;
            if (windowFreq[leftChar] == 0)
                windowFreq.erase(leftChar);
        }

        // Compare window frequency map with pattern frequency map
        if (windowFreq == patternFreq)
            return true;
    }

    return false;
}

bool checkInclusion2(string s1, string s2) {
    std::unordered_map<char , int>  patternFreq;
    std::unordered_map<char , int>  windowFreq;
    // std::vector<int> patternFreq(128 . 0);
    // std::vector<int>  windowFreq(128 . 0);

    // if s1 less than s2 then return false;
    if(s1.length()>s2.length())
        return false;
    // Populate pattern frequency map
    //fill the  patternFreq by s1 character, windowFreq  by s2 character until length s1
    int indexPatternWindow = 0;
    while(indexPatternWindow< s1.length() ){
        patternFreq[s1[indexPatternWindow]]++;
        windowFreq [s2[indexPatternWindow]]++;
        indexPatternWindow++;
    }
    //s1=[a b] ->indexPatternWindow = s2.end()==2
    //s2=[e i d b a o o o ] -> windowEnd=i , windowStart=e
    int windowEnd = indexPatternWindow-1;// to point at the last rightChar
    int windowStart = 0;
    cout<<s2[windowEnd]<<endl;
    while( windowEnd < s2.length()) {

        // Compare window frequency map with pattern frequency map
        if (windowFreq == patternFreq){
            return true;
        }else{
            //s1=[a b] ->indexPatternWindow = s2.end()==2
            //s2=[e i d b a o o o ] -> windowEnd=i , windowStart=e
            windowEnd++;//extend slide window by increment windowEnd
            char rightChar = s2[windowEnd];
            char leftChar  = s2[windowStart];
            windowFreq[rightChar]++;
            windowFreq[leftChar]--;
            if (windowFreq[leftChar] == 0){
                windowFreq.erase(leftChar);
            }
            windowStart++;////extend slide window by increment windowStart
        }

    }

    return false;
}
int main() {
    // Test cases
    string s1_1 = "ab";
    string s2_1 = "eidbaooo";
    string s2_2 = "eidboaoo";

    cout << "Test case 1 for checkInclusion: ";
    if (checkInclusion(s1_1, s2_1))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    cout << "Test case 2 for checkInclusion: ";
    if (!checkInclusion(s1_1, s2_2))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    cout << "Test case 1 for checkInclusion2: ";
    if (checkInclusion2(s1_1, s2_1))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    cout << "Test case 2 for checkInclusion2: ";
    if (!checkInclusion2(s1_1, s2_2))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    return 0;
}
