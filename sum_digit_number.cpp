#include<iostream>
#include<cstring>
#include<algorithm>
#include <bitset>



using namespace std;

uint32_t sum_digit_number_c(uint32_t number){
    uint32_t result = 0;
    while(number != 0){
        result =result +(number % 10);
        number =number/10;
    }
    return result;
}


int main(){

    cout<<"---------------------reverse_number_c-----------------"<<endl;
    unsigned int number = 2576980377 ; //16 zero   , 16 one
    cout<<"sum_digit_number=" << sum_digit_number_c(12345)<<endl;


    return 0;
}