#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<unordered_map>
#include<sstream>


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
#define NUM_CHAR 128U
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

int getSizeOfFreqArray(char * freq_char){
    int size =0;
    for (int i = 0; i < NUM_CHAR; i++){
        if(freq_char[i] >0){
            size++;
        }
    }
    return size;
}
char * k_unique_characters_string_c(char *cstring){
    if(cstring== nullptr)
        return NULL;
    int len  = strlen(cstring);
    char freq_char[NUM_CHAR]={0};
    char long_unique_substr[len-1];// we sub 1 because string come with K in index zero ("3aabacbebebe")
    int max_substr =0;
    int index_substr=0;

    if(!isdigit(cstring[0])){
        return NULL;
    }
    int  k = cstring[0]-'0';   //we convert the digit from character to integer
    int l =1 , h = 1 ,  max=0; // l = h = 1 because we start from index 1
    int count_character=0;

    while(l <= len && h <= len){
        freq_char[cstring[h]]++;
        int size = getSizeOfFreqArray(freq_char);
        count_character++;
        if(size >k){
            if(count_character > max_substr){
                max_substr = count_character;
                index_substr=0;//initialize  index_substr by zero to start from beginning
                for (int i = l; i <h; i++){
                    long_unique_substr[index_substr]=cstring[i];
                    index_substr++;
                }
                long_unique_substr[index_substr]='\0';                
            }
                freq_char[cstring[l]]--;
                l++;
                count_character--;
        }
        h++;
    }
    cout<<"the substr is:"<<long_unique_substr<<endl;
    return NULL;
}

string KUniqueCharacters_v2(string str) {
  const size_t k{static_cast<size_t>(str[0] - '0')};


  const size_t str_len{str.length()};

  size_t current_substr_len{str_len - 1};

  while (current_substr_len >= k) {
    unordered_map<char, size_t> char_freq{};

    for (size_t i{1}; i <= current_substr_len; i++)
      char_freq[str[i]]++;

    for (size_t i{1}; i + current_substr_len <= str_len; i++) {
      if (i > 1) {
        char_freq[str[i - 1]]--;
        if (0 == char_freq[str[i - 1]])
          char_freq.erase(str[i - 1]);

        char_freq[str[i + current_substr_len - 1]]++;
      }

      if (k == char_freq.size())
        return str.substr(i, current_substr_len);
    }

    current_substr_len--;
  }

  ostringstream oss{};

  oss << "Could not find sub-string with " << k << " unique characters!";
  return oss.str();
}
int main(){

    cout<<"---------------------k_unique_characters_string_c-----------------"<<endl;
    char cstring[]="3aabacbebebe" ; // "2aabbcbbbadef";//"2aabbcbbbadef";
    cout<<"the origin:"<<cstring<<endl;
    char * pointer = k_unique_characters_string_c(cstring);
    //cout<<KUniqueCharacters_v2(cstring)<<endl;
    //cout<<"k_unique_characters is:"<<pointer<<endl;

    return 0;
}