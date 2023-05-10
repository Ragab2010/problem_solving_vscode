#include <iostream>
#include <cstring>
#include <cstdio>


/*
Coderbyte coding challenge: K Unique Characters

Using the C++ language, have the function KUniqueCharacters(str) take the str
parameter being passed and find the longest substring that contains k unique
characters, where k will be the first character from the string. The substring
will start from the second position in the string because the first character
will be the integer k. For example: if str is "2aabbacbaa" there are several
substrings that all contain 2 unique characters, namely: ["aabba", "ac", "cb",
"ba"], but your program should return "aabba" because it is the longest
substring. If there are multiple longest substrings, then return the first
substring encountered with the longest length. k will range from 1 to 6.

Sample test cases:

Input:  "3aabacbebebe"
Output: "cbebebe"

Input:  "2aabbcbbbadef"
Output: "bbcbbb"
*/

using namespace std;
char* KUniqueCharacters(char* str) {
    int k = str[0] - '0'; // convert first char to int
    int len = strlen(str) - 1; // exclude first char from length
    int start = 1, end = 1, max_start = 1, max_end = 1;
    int count[128] = {0}; // count array for each ASCII character
    int unique = 0;

    for (; end <= len; end++) {
        if (count[str[end]]++ == 0) { // increment count and check for uniqueness
            unique++;
        }

        while (unique > k) { // move start pointer until unique characters <= k
            if (count[str[start++]]-- == 1) { // decrement count and check for uniqueness
                unique--;
            }
        }

        if (end - start > max_end - max_start) { // update max substring indices
            max_start = start;
            max_end = end;
        }
    }

    str[max_end + 1] = '\0'; // terminate substring with null character
    return str + max_start; // return pointer to max substring
}

int main() {
    cout<<"---------------------K Unique Characters-----------------"<<endl;

    char str1[] = "3aabacbebebe";
    char str2[] = "2aabbcbbbadef";
    printf("%s\n", KUniqueCharacters(str1)); // expected output: "cbebebe"
    printf("%s\n", KUniqueCharacters(str2)); // expected output: "bbcbbb"
    return 0;
}
