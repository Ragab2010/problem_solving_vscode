#include<iostream>


using namespace std;
#define BITS (sizeof(uint32_t)*8)

//the MSB IS ONE  when the number is Negative
bool is_positive(int32_t number){
    return ( ( number & (1u << (BITS -1 )))  | !number);
    // not number is for check the ZERO
}



int main(){

    cout<<"---------------------is_positive-----------------"<<endl;
    unsigned int number = -15 ; 
    cout<<std::boolalpha<<"is_positive=" << is_positive(210)<<endl;
    return 0;
}
