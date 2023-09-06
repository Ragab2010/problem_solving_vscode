#include<iostream>
#include<algorithm>
#include <bitset>



using namespace std;
int count_most_consecutive_one_c(uint32_t number){
    if(number == 0)
        return 0;
    int max=0 , count=0;
    while(number){
        
        if(number & 1){
            count++;
            if(count >= max){
                max = count;
            }
        }else{
            count=0;
        }
        number >>=1;
    }
    
    return max;
}
int count_most_consecutive_one_v1_c(uint32_t number){
    if(number == 0)
        return 0;
    int max=0;
    while(number){
        int count=0;
        while(number & 1){
            count++;
            number >>=1;
        }
        if(count >= max){
            max = count;
        }
        number >>=1;
    }
    
    return max;
}


int count_most_consecutive_one_cpp(uint32_t number) {
    if(number ==0)
        return 0;
    std::bitset<sizeof(uint32_t)*8> bits(number); // convert the integer to a bitset
    int max = 0;
    int count = 0;
    
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] == 1) {
            count++;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
    }
    
    return max;
}

int count_most_consecutive_one_v1_cpp(uint32_t number)  {
    std::bitset<sizeof(uint32_t)*8> bits(number); // convert the integer to a bitset
    
    int max = 0;
    int count = 0;
    
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits.test(i)) {
            count++;
        } else {
            max = std::max(max, count);
            count = 0;
        }
    }
    
    return std::max(max, count);
}



int main(){

    uint32_t number=0x50FF0F6 ; //8
    cout<<"---------------------count_most_consecutive_one_c-----------------"<<endl;
    cout<<"the max consecutive one :"<<count_most_consecutive_one_c(number)<<endl;

    cout<<"---------------------count_most_consecutive_one_v1_c-----------------"<<endl;
    cout<<"the max consecutive one :"<<count_most_consecutive_one_v1_c(number)<<endl;

    cout<<"---------------------count_most_consecutive_one_cpp-----------------"<<endl;
    cout<<"the max consecutive one :"<<count_most_consecutive_one_cpp(number)<<endl;

    cout<<"---------------------count_most_consecutive_one_v1_cpp-----------------"<<endl;
    cout<<"the max consecutive one :"<<count_most_consecutive_one_v1_cpp(number)<<endl;

    return 0;
}