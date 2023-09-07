#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>




using namespace std;
int count_most_ones_between_zeros_number_c(uint32_t number){
    int max = 0;
    int count = 0;
    while(number != 0){
        if(!(number & 1)){ //if the lsb is zero
            number = number >>1;
            while(number & 1){  //while the lsb is one
                    count++;
                number = number >>1;
            }
            
        }else{
            number = number >>1;
        }
        if(count> max )
            max = count ;
        count=0;
    }
    return max;    
}

//prefer
int count_most_ones_between_zeros_number_c_v1(uint32_t input){

    int count =0; 
    int max = 0;
    while(input){
        if(input & 1){
            count++;
        }else{
            if(count > max)
                max = count;
            count=0;
        }
        input >>=1;
    }
    return max;
}


int count_most_ones_between_zeros_number_cpp(uint32_t number) {
    std::bitset<32> binary(number);
    string cppstring = binary.to_string();
    int len = cppstring.size();
    int max = 0;
    for (int i = 0; i < len; i++) {
        if (cppstring[i] == '0') {
            int count = strspn(&cppstring[i] + i, "1");
            //cout<<count<<endl;
            if (count > max) {
                max = count;
            }
        }
    }
    return max;    
}


int main(){
    cout<<"---------------------count_most_ones_between_zeros_string_c-----------------"<<endl;
    uint32_t number=52982; // has 4 ones between zeros
    cout<<"the number:"<<number<<endl;

    cout<<"the max count   :"<<count_most_ones_between_zeros_number_c(number)<<endl;
    cout<<"---------------------count_most_ones_between_zeros_string_cpp-----------------"<<endl;
    cout<<"the max count   :"<<count_most_ones_between_zeros_number_cpp(number)<<endl;
    cout<<"---------------------count_most_ones_between_zeros_string_c_v1-----------------"<<endl;
    cout<<"the max count   :"<<count_most_ones_between_zeros_number_c_v1(number)<<endl;




    return 0;
}