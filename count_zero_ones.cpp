#include<iostream>
#include<cstring>
#include<algorithm>
#include <bitset>



using namespace std;
typedef struct z_o{
    int numOfZero;
    int numOfOne;
}zero_one_t;

zero_one_t count_zero_one_c(uint32_t number){
    zero_one_t result={0,0};
    while(number != 0){
        if(number & 1){
            result.numOfOne++;
        }else{
            result.numOfZero++;
        }
        number >>=1;
    }
    return result;
}

pair<int , int> count_zero_one_cpp(uint32_t number){
    std::bitset<32> binary(number); // convert to binary representation
    //int one= std::count(binary.to_string().begin() ,binary.to_string().end() , '1');
    int one= binary.count();//to count ones
    int zero= (sizeof(number)*8) - one;
    return make_pair(one , zero);
}

int main(){

    cout<<"---------------------count_zero_ones_c-----------------"<<endl;
    unsigned int number = 2576980377 ; //16 zero   , 16 one
    zero_one_t re = count_zero_one_c(number);
    cout<<"the number of zero :"<<re.numOfZero<<endl;
    cout<<"the number of one  :"<<re.numOfOne<<endl;

    cout<<"---------------------count_zero_ones_cpp-----------------"<<endl;
    pair<int , int> re_cpp = count_zero_one_cpp(number);
    cout<<"the number of zero :"<<re_cpp.second<<endl;
    cout<<"the number of one  :"<<re_cpp.first<<endl;
    return 0;
}