#include<iostream>
#include<bitset>


using namespace std;

void convert_decimal_to_binary_onScreen_c(uint32_t number){
    // if(number <=0)
    //     return  false;
    uint32_t shift_number =(sizeof(number) * 8) - 1;
    uint32_t shift_number_counter =(sizeof(number) * 8);
    while (shift_number_counter){
        if(number &(1ul<<shift_number)){
            cout<<"1";
        }else{
            cout<<"0";
        }
        number <<=1UL;
        shift_number_counter--;
    }
    cout<<endl;
}

void convert_decimal_to_binary_onScreen_c_v1(uint32_t number){
    // if(number <=0)
    //     return  false;

    uint32_t number_digit =(sizeof(number) * 8) - 1; //4byte * 8bit -1
    uint32_t shift_number =(1ul<<number_digit);
    
    while (shift_number){
        if(number &(shift_number)){
            cout<<"1";
        }else{
            cout<<"0";
        }
        shift_number >>=1UL;
    }
    cout<<endl;
}

char * convert_decimal_to_binary_instring_c(uint32_t number){

    char * ptr_binary =(char *)malloc(sizeof(char)*sizeof(number)*8);

    uint32_t number_digit =(sizeof(number) * 8) - 1; //4byte * 8bit -1
    uint32_t shift_number =(1ul<<number_digit);
    char* binary = ptr_binary;
    while (shift_number){
        if(number & shift_number){
            *binary='1';
        }else{
            *binary='0';
        }
        shift_number >>=1UL;
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
    convert_decimal_to_binary_onScreen_c(4);
    cout<<"---------------------convert_decimal_to_binary_onScreen C , Cpp v1 -----------------"<<endl;
    convert_decimal_to_binary_onScreen_c_v1(4);

    cout<<"---------------------convert_decimal_to_binary_instring C , Cpp -----------------"<<endl;
    cout<<convert_decimal_to_binary_instring_c(2147483743)<<endl;
    cout<<"---------------------convert_decimal_to_binary_instringCpp -----------------"<<endl;
    cout<<convert_decimal_to_binary_instring_cpp(2147483743)<<endl;


    return 0;
}