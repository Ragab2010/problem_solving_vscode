/*
Coderbyte coding challenge: Triple Double

Using the C++ language, have the function TripleDouble(num1,num2) take both
parameters being passed, and return 1 if there is a straight triple of a number
at any place in num1 and also a straight double of the same number in num2. For
example: if num1 equals 451999277 and num2 equals 41177722899, then return 1
because in the first parameter you have the straight triple 999 and you have a
straight double, 99, of the same number in the second parameter. If this isn't
the case, return 0.

Sample test cases:
Input:  465555 & num2 = 5579
Output: 1

Input:  67844 & num2 = 66237
Output: 0
*/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cstring>

using namespace std;

int TripleDouble_v1(int64_t num1, int64_t num2) {
  const string num1_str{to_string(num1)};
  const string num2_str{to_string(num2)};

  for (char digit{'0'}; digit <= '9'; digit++) {
    if ((end(num1_str) != search_n(begin(num1_str), end(num1_str), 3, digit)) &&
        (end(num2_str) != search_n(begin(num2_str), end(num2_str), 2, digit)))
      return 1;
  }

  return 0;
}

int TripleDouble_v2(int64_t num1, int64_t num2) {
  const string num1_str{to_string(num1)};
  const string num2_str{to_string(num2)};

  unordered_map<char, size_t> digit_count{};

  for (const char digit : num1_str)
    digit_count[digit]++;

  for (const pair<char, size_t>& digit_freq : digit_count) {
    if (digit_freq.second < 3)
      continue;

    if (end(num2_str) !=
        search_n(begin(num2_str), end(num2_str), 2, digit_freq.first))
      return 1;
  }

  return 0;
}

int TripleDouble_v3(int64_t num1, int64_t num2) {
  unordered_set<int64_t> found_digits{};

  size_t digit_count{1};
  int64_t prev_digit{num1 % 10};
  num1 /= 10;

  while (num1) {
    const int64_t current_digit{num1 % 10};
    num1 /= 10;

    if ((-1 != prev_digit) && (current_digit == prev_digit)) {
      digit_count++;
      if (3 == digit_count) {
        prev_digit = -1;
        found_digits.insert(current_digit);
      }

    } else if (-1 == prev_digit || current_digit != prev_digit) {
      prev_digit = current_digit;
      digit_count = 1;
    }
  }

  if (found_digits.empty())
    return 0;

  do {
    prev_digit = num2 % 10;
    num2 /= 10;

  } while (!found_digits.count(prev_digit));

  while (num2) {
    const int64_t current_digit{num2 % 10};
    num2 /= 10;

    if (!found_digits.count(current_digit)) {
      prev_digit = -1;
      continue;
    }

    if ((-1 != prev_digit) && (current_digit == prev_digit))
      return 1;
    else if (-1 == prev_digit) {
      prev_digit = current_digit;
    }
  }

  return 0;
}
/*********************************Ragab******************************/
bool check(string str){
  int count =0;
  unordered_map<char , unsigned int> map;
  for(char& ch : str){
    if(map.find(ch) !=map.end()){
      map[ch]++;
      count++;
    }else{
      map[ch]++;
      count=1;
    }
    if(count>2){
      return true;
    }
  }
  return false;
}
int TripleDouble_cpp_v1(int64_t num1, int64_t num2) {
  std::string str_num1{to_string(num1)};
  std::string str_num2{to_string(num2)};
  int count =0;
  
  bool str_num1_status = check(str_num1);
  bool str_num2_status = check(str_num2);
  if(str_num1_status==true || str_num2_status == true){
    return 1;
  }
  return 0;

}
/************************slid_Window**********************/
bool check_consecutive_characters(const char *cstring , int len){
  int l = 0 , h=0;
  int count =0;
  while(l<len && h <len){
    if(cstring[l] == cstring[h]){
      count++;
      h++;
    }else{
      l++;
      count--;
    }
    if(count>2){
      return true;
    }
  }
  return false;
}

int TripleDouble_c_v1(int64_t num1, int64_t num2) {
  char str_num1[50];
  char str_num2[50];
  sprintf(str_num1,"%ld" , num1);
  sprintf(str_num2,"%ld" , num1);
  int len1 =strlen(str_num1);
  int len2 =strlen(str_num2);
  bool str_num1_status = check_consecutive_characters(str_num1 , len1);
  bool str_num2_status = check_consecutive_characters(str_num2 , len2);
  if(str_num1_status==true || str_num2_status == true){
    return 1;
  }
  return 0;
}

int main() {
  // cout << TripleDouble_v1(gets(stdin));
  cout<<"---------------------TripleDouble_v1-----------------"<<endl;
  cout << TripleDouble_v1(451999277LL, 41177722899LL)
       << '\n';                                       // expected output: 1
  cout << TripleDouble_v1(465555LL, 5579LL) << '\n';  // expected output: 1
  cout << TripleDouble_v1(67844LL, 66237LL) << '\n';  // expected output: 0
  cout<<"---------------------TripleDouble_cpp_v1-----------------"<<endl;
  cout << TripleDouble_cpp_v1(451999277LL, 41177722899LL) << '\n'; // expected output: 1
  cout << TripleDouble_cpp_v1(465555LL, 5579LL) << '\n';               // expected output: 1
  cout << TripleDouble_cpp_v1(67844LL, 66237LL) << '\n';               // expected output: 0

  cout<<"---------------------TripleDouble_c_v1-----------------"<<endl;
  cout << TripleDouble_c_v1(451999277LL, 41177722899LL) << '\n'; // expected output: 1
  cout << TripleDouble_c_v1(465555LL, 5579LL) << '\n';               // expected output: 1
  cout << TripleDouble_c_v1(67844LL, 66237LL) << '\n';               // expected output: 0

  return 0;
}
