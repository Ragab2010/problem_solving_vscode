#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int strLength = s.size();
    int length = 0, maxLength = 0;
    int startWindow = 0, endWindow = 0;
    int freq[128] = {0};
    
    for (endWindow = 0; endWindow < strLength; endWindow++) {
        char ch = s[endWindow];
        if (freq[ch] != 0) {
            startWindow = max(startWindow, freq[ch]);
        }
        freq[ch] = endWindow + 1;
        maxLength = max(maxLength, endWindow - startWindow + 1);
    }
    return maxLength;
}

int main() {
    // Test cases
    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";

    cout << "Test 1: Length of longest substring without repeating characters in \"" << test1 << "\" is " << lengthOfLongestSubstring(test1) << endl;
    cout << "Test 2: Length of longest substring without repeating characters in \"" << test2 << "\" is " << lengthOfLongestSubstring(test2) << endl;
    cout << "Test 3: Length of longest substring without repeating characters in \"" << test3 << "\" is " << lengthOfLongestSubstring(test3) << endl;

    return 0;
}
