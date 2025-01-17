/*
Coderbyte coding challenge: Binary Converter

Using the C++ language, have the function BinaryConverter(str) return the
decimal form of the binary value. For example: if 101 is passed return 5, or if
1000 is passed return 8.

Sample test cases:

Input:  "100101"
Output: "37"

Input:  "011"
Output: "3"
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string trim(const string& input) {
  string output{input};
  output.erase(begin(output),
               find_if(begin(output), end(output),
                       [](const char ch) { return !isspace(ch); }));

  output.erase(find_if(output.rbegin(), output.rend(),
                       [](const char ch) { return !isspace(ch); })
                   .base(),
               end(output));

  return output;
}

bool is_valid_binary_string(const string& str) {
  return all_of(begin(str), end(str),
                [](const char ch) { return (ch == '0' || ch == '1'); });
}

string BinaryConverter_v1(string str) {
  str = trim(str);

  if (!is_valid_binary_string(str))
    return "not possible";

  int decimal_number{};

  for (const char ch : str) {
    decimal_number <<= 1;
    decimal_number |= static_cast<int>(ch - '0');
  }

  return to_string(decimal_number);
}

string BinaryConverter_v2(string str) {
  str = trim(str);

  if (!is_valid_binary_string(str))
    return "not possible";

  const size_t str_len{str.length()};
  cout<<"the len= "<<str.length()<<endl;

  int decimal_number{};


  for (size_t i{} , j{str_len-1} ; i <str_len; i++ , j--) {
    if ('0' == str[i])
      continue;
    cout<<"str["<<i<<"]="<<str[i]<<endl;
    decimal_number += (1 << (j));
  }

  return to_string(decimal_number);
}

string BinaryConverter_v3(string str) {
  str = trim(str);

  if (!is_valid_binary_string(str))
    return "not possible";
    /*stoi:convert string to integer ->int stoi (const string&  str, size_t* idx = 0, int base = 10),
    str -> string
    idx->Pointer to an object of type size_t, set by the function to position of the next character in str after the numerical value.
    Numerical base (radix) , 10 , 2 , 0-> zero  for the format sequance 
    */
   //to_string-> convert integer tor string
  return to_string(stoi(str, nullptr, 2));
}

string BinaryConverter_v4(string str) {
  str = trim(str);

  if (!is_valid_binary_string(str))
    return "not possible";
    /*stoi:convert string to integer ->int stoi (const string&  str, size_t* idx = 0, int base = 10),
    str -> string
    idx->Pointer to an object of type size_t, set by the function to position of the next character in str after the numerical value.
    Numerical base (radix) , 10 , 2 , 0-> zero  for the format sequance 
    */
   //to_string-> convert integer tor string
  return to_string(strtol(str.data() , nullptr , 2));
}

int main() {
  // cout << BinaryConverter_v1(move(string{gets(stdin)}));
  cout << BinaryConverter_v1(move(string{"101"}))
       << '\n';  // expected output: 5
  cout << BinaryConverter_v2(move(string{"1000"}))
       << '\n';  // expected output: 8
  cout << BinaryConverter_v3(move(string{"100101"}))
       << '\n';  // expected output: 37
  cout << BinaryConverter_v4(move(string{"011"}))
       << '\n';  // expected output: 3


  return 0;
}