/*
Coderbyte coding challenge: Permutation Step

Using the C++ language, have the function PermutationStep(num) take the num
parameter being passed and return the next number greater than num using the
same digits. For example: if num is 123 return 132, if it's 12453 return 12534.
If a number has no greater permutations, return -1 (ie. 999).

Sample test Cases:

Input:  11121
Output: 11211

Input:  41352
Output: 41523
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int PermutationStep_cpp(const int num) {
  string num_str{to_string(num)};

  const bool is_next_permutation_available{
      next_permutation(begin(num_str), end(num_str))};

  if (!is_next_permutation_available)
    return -1;

  return stoi(num_str);
}

void swap(char *str  , int index , int len ){

    while(index < len-1 ){
        char temp = str[index];
        str[index] = str[index+1];
        str[index+1] =temp; 
        index++;
    }
}
int PermutationStep_c(const int num) {
 char cString[50];
    sprintf(cString , "%d" , num);
    int len = strlen(cString);
    //cout<<len<<endl;
   for(int i =len-1 ; i>0; i-- ){
       if(cString[i] > cString[i-1]){
           swap(cString , i-1 , len );
           break;
       }
   }

  return stoi(cString);
}


int main() {
  // cout << PermutationStep(gets(stdin));
    cout<<"---------------------PermutationStep_cpp-----------------"<<endl;

    cout << PermutationStep_cpp(123) << '\n';    // expected output: 132
    cout << PermutationStep_cpp(12453) << '\n';  // expected output: 12534
    cout << PermutationStep_cpp(11121) << '\n';  // expected output: 11211
    cout << PermutationStep_cpp(41352) << '\n';  // expected output: 41523
    
    cout<<"---------------------PermutationStep_c-----------------"<<endl;

    cout << PermutationStep_c(123) << '\n';    // expected output: 132
    cout << PermutationStep_c(12453) << '\n';  // expected output: 12534
    cout << PermutationStep_c(11121) << '\n';  // expected output: 11211
    cout << PermutationStep_c(41352) << '\n';  // expected output: 41523


  return 0;
}