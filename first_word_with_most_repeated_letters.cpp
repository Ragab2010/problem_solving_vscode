/*
Coderbyte coding challenge: Letter Count

Using the C++ language, have the function LetterCount(str) take the str
parameter being passed and return the first word with the greatest number of
repeated letters. For example: "Today, is the greatest day ever!" should return
greatest because it has 2 e's (and 2 t's) and it comes before ever which also
has 2 e's. If there are no words with repeating letters return -1. Words will be
separated by spaces.

Sample test cases:

Input:  "Hello apple pie"
Output: "Hello"

Input:  "No words"
Output: "-1"
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <vector>

#include <cstring>
#include <cctype>

using namespace std;
char * LetterCount_vif(const char * cstring ){
    static char result[60];
    strcpy(result , "-1");
    int index_reslut=0;
    if(cstring== nullptr)
        return result;
    int len = strlen(cstring);
    if(len <=1)
        return result;
    int freq_char [128]={0};
    int max = 0;
    int l = 0 , h= 0;
    while(l< len ){
        /*
        while (!isalnum(cstring[l]) && l< len){
            l++;
        }*/
        //replace while by if && remove l< len
        if (!isalnum(cstring[l]) ){
            l++;
            //add continue
            continue;
        }
        int freq_char [128]={0};
        int count =0;
        int start_index = l;
        while (isalnum(cstring[l]) && l< len){
          //here we check the number of repeted char only 
            freq_char[cstring[l]]++;
            if(freq_char[cstring[l]] >1){
                count++;   
            }
            l++;
        }
        if(count > max){
            max = count;
            for (int i = start_index; i < l; i++){
                result[index_reslut] = cstring[i];
                index_reslut++;
            }
            result[index_reslut] = '\0';
        }

    }
    return result;
}

char * LetterCount_v0(const char * cstring ){
    static char result[60];
    strcpy(result , "-1");
    int index_reslut=0;
    if(cstring== nullptr)
        return result;
    int len = strlen(cstring);
    if(len <=1)
        return result;
    int freq_char [128]={0};
    int max = 0;
    int l = 0 , h= 0;
    while(l< len ){
        while (!isalnum(cstring[l]) && l< len){
            l++;
        }
        int freq_char [128]={0};
        int count =0;
        int start_index = l;
        while (isalnum(cstring[l]) && l< len){
            if(freq_char[cstring[l]] >0){
                count++;
                freq_char[cstring[l]]++;
            }else{
                freq_char[cstring[l]]++;
            }
            l++;
        }
        if(count > max){
            max = count;
            for (int i = start_index; i < l; i++){
                result[index_reslut] = cstring[i];
                index_reslut++;
            }
            result[index_reslut] = '\0';
        }

    }
    return result;
}


//prefer
std::string LetterCount(std::string str){
    std::stringstream ss(str);//create stream
    int max{};//max
    std::string result{}; //result string
    std::string word{}; //word for check
    while(ss>>word){
        std::unordered_map<char , int> map{};
        int count{};
        for(char ch : word){
            map[std::tolower(ch)]++;
            if(map[std::tolower(ch)] >1){
                count++;
            }
        }

        if(count > max ){
            max = count;
            result = word;
        }
        
    }

    return result;
}


string LetterCount_v1(string str) {


  const size_t str_len{str.length()};

  size_t start{};
  size_t count_of_max_repeated_letters{1};
  string word{};

  while (start < str_len) {
    start = str.find_first_not_of(' ', start);

    if (string::npos == start)
      break;

    size_t last{str.find_first_of(' ', start + 1)};

    if (string::npos == last)
      last = str_len;

    unordered_set<char> visited_chars{};
    size_t rep_char_count{};

    for (size_t i{start}; i < last; i++) {
      if (visited_chars.count(str[i]))
        continue;

      visited_chars.insert(str[i]);

      const auto ch_freq = count(begin(str) + start, begin(str) + last, str[i]);

      if (ch_freq > 1)
        rep_char_count += ch_freq;
    }

    if (rep_char_count > count_of_max_repeated_letters) {
      count_of_max_repeated_letters = rep_char_count;
      word = str.substr(start, last - start);
    }

    start = last + 1;
  }

  if (count_of_max_repeated_letters > 1)
    return word;

  return "-1";
}


int main() {
  // cout << LetterCount_v2(move(string{gets(stdin)}));
//   cout << LetterCount_v2(move(string{"Today, is the greatest day ever!"}))
//        << '\n';  // expected output: "greatest"
//   cout << LetterCount_v2(move(string{"Hello apple pie"}))
//        << '\n';  // expected output: "Hello"
//   cout << LetterCount_v2(move(string{"No words"}))
    //    << '\n';  // expected output: "-1"
  cout << LetterCount_vif("Today, is the greatest day ever!")<<endl;

  return 0;
}