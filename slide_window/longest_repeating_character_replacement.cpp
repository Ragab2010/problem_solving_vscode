#include <iostream>
#include <vector>
#include <algorithm>
//prefer
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
