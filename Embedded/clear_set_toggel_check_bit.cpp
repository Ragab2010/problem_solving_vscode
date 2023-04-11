#include<iostream>


using namespace std;

void clear_bit(uint32_t *number , uint32_t bit_number){
    *number &=~(1<<bit_number);
}
void set_bit(uint32_t *number , uint32_t bit_number){
    *number |=(1<<bit_number);
}
void toggel_bit(uint32_t *number , uint32_t bit_number){
    *number ^=(1<<bit_number);
}
uint32_t check_bit(uint32_t *number , uint32_t bit_number){
    return (*number & (1<<bit_number))>>bit_number;
}



int main(){

    uint32_t  number = 0b10001011 ; //139
    cout<<"the number is:"<<number<<endl;
    cout<<"---------------------clear_bit-----------------"<<endl;
    clear_bit(&number , 7);
    cout<<"the number fter clear is:"<<number<<endl;
    cout<<"---------------------check_bit-----------------"<<endl;
    cout<<"check_bit number 3=" << check_bit( &number , 3)<<endl;
    return 0;
}
