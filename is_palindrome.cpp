#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;
bool is_palindrome_string(const char * cstring ){
    if(cstring == NULL)
        return  false;
    int len = strlen(cstring);
    for (int i =0; i < len/2; i++){
        if(cstring[i] != cstring[len - i - 1]){
            return false;
        }
    }
    return true;
}
bool is_palindrome_integer(int num ){

    int reverseNum = 0;
    int tempOriginal = num;

    while (tempOriginal > 0) {

    int lastDigit = tempOriginal % 10;
    reverseNum = reverseNum * 10 + lastDigit;
    tempOriginal = tempOriginal / 10;
    }

    if (num == reverseNum) {
        return true;
    } else {
        return false;
    }
}



int main(){

    cout<<"---------------------is_palindrome_string-----------------"<<endl;
    bool string_stauts  = is_palindrome_string("abba");
    if(string_stauts == true)
        cout<<"the string is palindrome"<<endl;
    else
        cout<<"the string isn't palindrome"<<endl;


    cout<<"---------------------is_palindrome_integer-----------------"<<endl;
    bool number_stauts  = is_palindrome_integer(1221);
    if(number_stauts == true)
        cout<<"the number is palindrome"<<endl;
    else
        cout<<"the number isn't palindrome"<<endl;


    return 0;
}