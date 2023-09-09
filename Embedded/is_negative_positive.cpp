#include<iostream>


using namespace std;
#define BITS (sizeof(uint32_t)*8)

//the MSB IS ONE  when the number is Negative
bool is_positive(int32_t number){
    return !( ( number & (1u << (BITS -1 )))  );
    // not number is for check the ZERO
}

bool isPositive(int32_t number) {
    return number > 0;
}


int main(){

    cout<<"---------------------is_positive-----------------"<<endl;
    int number = 15 ; 
    cout<<std::boolalpha<<"is_positive=" << is_positive(number)<<endl;

    cout<<std::boolalpha<<"isPositive=" << isPositive(number)<<endl;
    return 0;
}
