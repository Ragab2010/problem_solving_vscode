#include<iostream>
#include<bitset>


using namespace std;

void convert_decimal_to_binary_onScreen_c(uint32_t number){
    // if(number <=0)
    //     return  false;
    uint32_t shift_number =(sizeof(number) * 8) - 1;
    while (number){
        if(number &(1<<shift_number)){
            cout<<"1";
        }else{
            cout<<"0";
        }
        number <<=1;
    }
    cout<<endl;
}

char * convert_decimal_to_binary_instring_c(uint32_t number){

    char * ptr_binary =(char *)malloc(sizeof(char)*sizeof(number)*8);
    uint32_t shift_number =(sizeof(number) * 8) - 1;
    char* binary = ptr_binary;
    while (number){
        if(number &(1<<shift_number)){
            *binary='1';
        }else{
            *binary='0';
        }
        number <<=1;
        binary++;
    }
    return ptr_binary;
}

string convert_decimal_to_binary_instring_cpp(uint32_t number){

    std::bitset<sizeof(number)*8> binary(number);

    string binary_string = binary.to_string();
    return binary_string;
}

int main(){

    cout<<"---------------------convert_decimal_to_binary_onScreen C , Cpp -----------------"<<endl;
    convert_decimal_to_binary_onScreen_c(2147483743);

    cout<<"---------------------convert_decimal_to_binary_instring C , Cpp -----------------"<<endl;
    cout<<convert_decimal_to_binary_instring_c(2147483743)<<endl;
    cout<<"---------------------convert_decimal_to_binary_instringCpp -----------------"<<endl;
    cout<<convert_decimal_to_binary_instring_cpp(2147483743)<<endl;


    return 0;
}