#include<iostream>


using namespace std;

uint32_t reverse_bits_c(uint32_t number){
    uint32_t result = 0;

    while(number != 0){
        result =(result *2)+(number % 2);
        number =number/2;

    }
    return result;
}
uint32_t reverse_bits_v2_c(uint32_t number){
    uint32_t result = 0;
    
    while(number != 0){
        if(number & 1){
            result = (result <<1) | 1;
        }else{
            result = (result <<1) ;
        }
        number =number>>1;
    }
    return result;
}


int main(){

    cout<<"---------------------reverse_bits_c-----------------"<<endl;
    unsigned int number = 2576980377 ; //16 zero   , 16 one
    cout<<"reverse_bits_c=" << reverse_bits_c(210)<<endl;
    cout<<"reverse_bits_v2_c=" << reverse_bits_v2_c(210)<<endl;
    return 0;
}
