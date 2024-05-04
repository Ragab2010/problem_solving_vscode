#include <iostream>
#include <string>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    int need[128]{};
    int window[128]{};

    int sSize = s.size(), tSize = t.size();

    for (char& c : t) {
        ++need[c];
    }

    int counter = 0, startWindow = 0, startIndex = -1, minLen = INT_MAX;
    for (int endWindow = 0; endWindow < sSize; ++endWindow) {
        ++window[s[endWindow]];
        if (need[s[endWindow]] >= window[s[endWindow]]) {
            ++counter;
        }
        while (counter == tSize) {
            if (endWindow - startWindow + 1 < minLen) {
                minLen = endWindow - startWindow + 1;
                startIndex = startWindow;
            }
            if (need[s[startWindow]] >= window[s[startWindow]]) {
                --counter;
            }
            --window[s[startWindow]];
            startWindow++;
        }
    }
    return startIndex < 0 ? "" : s.substr(startIndex, minLen);
}

int main() {
    // Test cases
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test Case 1:" << endl;
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Output: " << minWindow(s1, t1) << endl;
    cout << endl;

    string s2 = "a", t2 = "a";
    cout << "Test Case 2:" << endl;
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Output: " << minWindow(s2, t2) << endl;
    cout << endl;

    string s3 = "a", t3 = "aa";
    cout << "Test Case 3:" << endl;
    cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Output: " << minWindow(s3, t3) << endl;
    cout << endl;

    return 0;
}
