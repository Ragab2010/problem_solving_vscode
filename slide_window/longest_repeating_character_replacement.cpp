#include <iostream>
#include <vector>
#include <algorithm>
//prefer

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.


Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

*/
int characterReplacement(std::string s, int k) {
    std::vector<int> count(128);
    int maxCount = 0;
    
    int startWindow = 0;
    int endWindow = 0;
    
    int result = 0;
    
    while (endWindow < s.size()) {
        count[s[endWindow]]++;
        int rightChar= s[endWindow];
        maxCount = std::max(maxCount, count[rightChar ]);
        if (endWindow - startWindow + 1 - maxCount > k) {
        int leftChar= s[startWindow];
            count[leftChar]--;
            startWindow++;
        }
        result = std::max(result, endWindow - startWindow + 1);
        endWindow++;
    }
    
    return result;
}


int characterReplacement2(std::string s, int k) {
    std::vector<int> count(128);
    int maxCount = 0;
    
    int startWindow = 0;
    int endWindow = 0;
    
    int result = 0;
    
    while (endWindow < s.size()) {

        int rightChar= s[endWindow];
        count[rightChar]++;

        maxCount = std::max(maxCount, count[rightChar]);
        if (endWindow - startWindow + 1 - maxCount > k) {
        int leftChar= s[startWindow];
            count[leftChar]--;
            startWindow++;
        }
        endWindow++;
    }
    
    return endWindow - startWindow;
}

int main() {
    // Test cases
    std::string s1 = "ABAB";
    int k1 = 2;
    std::cout << "Input: s = \"" << s1 << "\", k = " << k1 << std::endl;
    std::cout << "Output: " << characterReplacement(s1, k1) << std::endl;
    
    std::string s2 = "AABABBA";
    int k2 = 1;
    std::cout << "Input: s = \"" << s2 << "\", k = " << k2 << std::endl;
    std::cout << "Output: " << characterReplacement(s2, k2) << std::endl;

    // Additional test cases
    std::string s3 = "AABBBCCCC";
    int k3 = 2;
    std::cout << "Input: s = \"" << s3 << "\", k = " << k3 << std::endl;
    std::cout << "Output: " << characterReplacement(s3, k3) << std::endl;

    std::string s4 = "AAAA";
    int k4 = 2;
    std::cout << "Input: s = \"" << s4 << "\", k = " << k4 << std::endl;
    std::cout << "Output: " << characterReplacement(s4, k4) << std::endl;

    return 0;
}
