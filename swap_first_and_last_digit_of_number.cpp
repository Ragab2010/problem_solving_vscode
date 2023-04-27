#include<iostream>
#include<cstring>
#include<algorithm>
#include <bitset>



using namespace std;

uint32_t  swap_first_and_last_digit_of_number_c(uint32_t number){
    uint32_t temp = number , result=0 , store_swap=0;
    uint32_t first_digit , last_digit;
    if (number == 0)
        return 0;
    //get last digit
    last_digit = temp%10;
    //get first digit
    while(temp){
        first_digit = temp%10;
        temp = temp/10;
    }

    temp =number;
    temp = temp/10;//drob the last digit
    while((temp/10) != 0){
        store_swap =(store_swap* 10) +(temp % 10);
        temp =temp/10;
    }
    cout<<"store_swap is "<<store_swap<<endl;

    result =result +last_digit;
    
    while(store_swap != 0){
        result =(result*10) +(store_swap % 10);
        store_swap =store_swap/10;
    }
    //put frist digit 
    result =result * 10;
    result =result +first_digit;

    return result;
}


int main(){

    cout<<"---------------------swap_first_and_last_digit_of_number_c-----------------"<<endl;
    unsigned int number = 12345 ; //16 zero   , 16 one
    cout<<"sum_digit_number=" << swap_first_and_last_digit_of_number_c(number)<<endl;


    return 0;
}