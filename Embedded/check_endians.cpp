#include<iostream>


using namespace std;
typedef union
{
    uint32_t u32RawData;  // integer variable
    uint8_t  au8DataBuff[4]; //array of character
} RawData;


int main(){
    cout<<"---------------------check Endian-----------------"<<endl;
    RawData uCheckEndianess;
    uCheckEndianess.u32RawData = 0x11223344; //assign the value
    if(uCheckEndianess.au8DataBuff[0]== 0x44){
        cout<<"little-endian"<<endl;
    }else{
        cout<<"big-endian"<<endl;
    }


    return 0;
}