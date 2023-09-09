/*
Coderbyte coding challenge: Time Convert

Using the C++ language, have the function TimeConvert(num) take the num
parameter being passed and return the number of hours and minutes the parameter
converts to (ie. if num = 63 then the output should be 1:3). Separate the
number of hours and minutes with a colon.

Sample test cases:

Input:  126
Output: "2:6"

Input:  45
Output: "0:45"
 */

#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

using namespace std;
char * TimeConvert_c(uint64_t minutes){
  uint64_t hours = minutes/60;
  uint64_t min = minutes%60;
  static char time[15]={0};
  int start_index=0;

  sprintf(time , "%lu:%lu" , hours , min);

  return time;
}

string TimeConvert(uint64_t minutes) {
  uint64_t hours{minutes / 60};
  minutes %= 60;
  string result;

  if (0 == minutes) {
    result.push_back('0');
  } else {
    while (minutes > 0) {
      result.push_back('0' + minutes % 10);
      minutes /= 10;
    }
  }

  result.push_back(':');

  if (0 == hours) {
    result.push_back('0');
  } else {
    while (hours > 0) {
      result.push_back('0' + hours % 10);
      hours /= 10;
    }
  }
cout<<"before reverse:"<<result<<endl;
  reverse(begin(result), end(result));

  return result;
}


int main() {
  std::cout<<"---------------------TimeConvert-----------------"<<endl;
  std::cout << TimeConvert(120) << '\n';  // expected output: "2:0"
  std::cout << TimeConvert(35) << '\n';   // expected output: "0:35"
  std::cout << TimeConvert(256) << '\n';  // expected output: "4:16"
  std::cout << TimeConvert(308) << '\n';  // expected output: "5:8"
  std::cout << TimeConvert(935) << '\n';  // expected output: "15:35"
  std::cout<<"---------------------TimeConvert_c-----------------"<<endl;
  std::cout << TimeConvert_c(120) << '\n';  // expected output: "2:0"
  std::cout << TimeConvert_c(35) << '\n';   // expected output: "0:35"
  std::cout << TimeConvert_c(256) << '\n';  // expected output: "4:16"
  std::cout << TimeConvert_c(308) << '\n';  // expected output: "5:8"
  std::cout << TimeConvert_c(935) << '\n';  // expected output: "15:35"


  return 0;
}
